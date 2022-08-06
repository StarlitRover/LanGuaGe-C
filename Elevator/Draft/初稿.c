#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
//#include <easyx.h>
#include <Windows.h>
#include <time.h>
#define isEmpty(q) (q->front->next==NULL)

int stories;

void* Animate(void* q);
void* psg(void* q);

typedef struct task
{
	int floor,flag;
	struct task* next;
}task;
task* initTask();
void insertTask(task* pre, task* tsk);

typedef struct elevator
{
	task* front, * rear;
}elevator;
elevator* initElevator();
void disposeElevator(elevator* q);
void deElevator(elevator* q);
void enElevator(elevator* q, int x, int drct);
int front(elevator* q);

int main()
{
	int crt;
	printf("��������¥������\n");
	scanf("%d", &stories);
	printf("�����õ�ǰ��������¥�㣺\n");
	scanf("%d", &crt);
	while (crt<1 || crt>stories)
	{
		printf("�ȿȡ�����ѵ��ݰ��������ˣ����������룺\n");
		scanf("%d", &crt);
	}
	printf("\n���ݻ����¼:\n");
	elevator* e = initElevator();
	e->front->floor = crt;
	srand(time(0));
	pthread_t ide[2];
	pthread_create(&ide[0], NULL, Animate, (void*)e);
	pthread_create(&ide[1], NULL, psg, (void*)e);
	pthread_exit(NULL);
	disposeElevator(e);
}

task* initTask()
{
	task* t = (task*)malloc(sizeof(task));
	t->floor = 1;
	t->flag = 0;
	t->next = NULL;
}

void insertTask(task* pre, task* tsk)
{
	task* tmp = pre->next;
	pre->next = tsk;
	tsk->next = tmp;
}

elevator* initElevator()
{
	elevator* q = (elevator*)malloc(sizeof(elevator));
	q->rear = q->front = initTask();
	q->front->floor = 1;
	return q;
}

void disposeElevator(elevator* q)
{
	task* tmp = q->front, * clone = tmp;
	while (tmp)
	{
		clone = clone->next;
		free(tmp);
		tmp = clone;
	}
	free(q);
}

void deElevator(elevator* q)
{
	if (isEmpty(q))
		return;
	task* tmp = q->front->next;
	q->front->next = tmp->next;
	if (tmp->next == NULL)
		q->rear = q->front;

	if (tmp->flag != 0)
	{
		int floor = tmp->floor;
		printf("@ %d¥�˿ͽ�����ݣ�", floor);
		//srand(time(0));
		if (tmp->flag == 1 && stories != floor)
		{
			floor += (rand() % (stories - floor) + 1);
			printf("��������%d¥������\n", floor);
		}
		else
		{
			floor -= (rand() % floor);
			printf("��������%d¥������\n", floor);
		}
		enElevator(q, floor, 0);
	}
	else
		printf("@ �˿ͳ����ݡ�\n");
	free(tmp);
}

void enElevator(elevator* q, int x, int drct)
{
	task* nxt = q->front->next, * loc = NULL;
	for (task *tmp = q->front; tmp != NULL; tmp = tmp->next)
	{
		if (tmp->floor == x)
			return;
		if (loc == NULL && nxt != NULL && (x > tmp->floor) == (x < nxt->floor) && drct * (tmp->floor > nxt->floor ? -1 : 1) >= 0)
			loc = tmp;
		if (nxt != NULL)
			nxt = nxt->next;
	}
	task* tsk = initTask();
	tsk->floor = x;
	tsk->flag = drct;
	if (loc != NULL)
		insertTask(loc, tsk);
	else
		q->rear = q->rear->next = tsk;

	//���·��
	printf("# ���ݵ�·�߽���Ϊ��%d", q->front->floor);
	task* tmp = q->front->next;
	while (tmp != NULL)
	{
		printf("->%d", tmp->floor);
		tmp = tmp->next;
	}
	printf("\n");
}

int front(elevator* q)
{
	if (!isEmpty(q))
		return q->front->next->floor;
	else
		return 0;
}

void* Animate(void *q)
{
	elevator* e = (elevator*)q;
	while (1)
	{
		if (isEmpty(e))
		{
			printf("& ����ing~\n");
			Sleep(2000);
			continue;
		}
		else
		{
			if (e->front->floor == front(e))
			{
				printf("^ �����ѵ�%d¥,����ing~\n", front(e));
				Sleep(2000);
				deElevator(e);
			}
			else
			{
				int crt = e->front->floor, tgr = front(e);
				e->front->floor += (crt > tgr ? -1 : 1);
				printf("- ����Ŀǰ������%d¥����\n", e->front->floor);
				Sleep(1000);
			}
		}
	}
}

void* psg(void* q)
{
	elevator* e = (elevator*)q;
	//srand(time(0));
	while(1)
	{
		int opt = rand() % stories + 1;
		int time = rand()%30;
		printf("@ %d¥�˿Ͱ�����", opt);
		switch (time % 2)
		{
		case 0:
			printf("��¥��\n");
			break;
		case 1:
			printf("��¥��\n");
			break;
		}
		enElevator(e, opt, 2*(time%2)-1); //��0��1ӳ��Ϊ-1��1
		Sleep(time*1000);
	}
}