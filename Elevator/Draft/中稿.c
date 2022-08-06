#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
//#include <easyx.h>
#include <Windows.h>
#include <time.h>
#include<math.h>
#define isEmpty(q) (q->front->next==NULL)
#define MAXITVL_PSG 30
#define ITVL_ELVT 1

int stories;

void* Animate(void* q);
void* psg(void* q);

typedef struct task
{
	int floor, flag;
	struct task* next;
}task;
task* initTask();
void insertTask(task* pre, task* tsk);
//void shiftTask(task* dst, task* pre);

typedef struct elevator
{
	task* front, * rear;
	int status;
}elevator;
elevator* initElevator();
void disposeElevator(elevator* q);
void deElevator(elevator* q);
void alterpsg(elevator* q, int floor, int flag);
void enElevator(elevator* q, int x, int drct);
int front(elevator* q);

int main()
{
	int crt;
	printf("��������¥������\n");
	scanf("%d", &stories);
	while (stories < 1 || stories >= 1000)
	{
		printf("���Ѳ�����������������������루1-999����\n");
		scanf("%d", &stories);
	}
	printf("�����õ�ǰ��������¥�㣺\n");
	scanf("%d", &crt);
	while (crt<1 || crt>stories)
	{
		printf("�ȿȡ���ѵ��ݰ��������ˣ����������룺\n");
		scanf("%d", &crt);
	}
	printf("\n          $���ݻ���Ӽ�¼$\n");
	printf("?*?*?*?*?*?*?*?*?*?*?*?*?\n");
	elevator* e = initElevator();
	e->front->floor = crt;
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
	return t;
}

void insertTask(task* pre, task* tsk)
{
	task* tmp = pre->next;
	pre->next = tsk;
	tsk->next = tmp;
}

//void shiftTask(task* dst, task* pre)
//{
//	task* tsk = pre->next;
//	pre->next = tsk->next;
//	tsk->next = dst->next;
//	dst->next = tsk;
//}

elevator* initElevator()
{
	elevator* q = (elevator*)malloc(sizeof(elevator));
	q->rear = q->front = initTask();
	q->front->floor = 1;
	q->status = 0;
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
		q->rear = q->front; //֮���Բ����������if�Ƿ�ֹ��(*)�н�ֵ��ֵ��NULL

	alterpsg(q, tmp->floor, tmp->flag); //alterpsg��������ifǰ����Ϊ(#)�е�flag���ǵ�

	if (tmp->next == NULL) //ָ�������if
		q->status = 0;
	else
		q->status = (q->front->floor > q->front->next->floor ? -1 : 1);

	free(tmp);
}

void alterpsg(elevator* q, int floor, int flag)
{
	if (flag != 0)
	{
		printf(">> %d¥�˿ͽ�����ݣ�", floor);
		srand(time(0));
		if (flag == 1 && stories != floor)
			floor += (rand() % (stories - floor) + 1);
		else
			floor -= (rand() % floor);
		printf("��������%d¥����\n", floor);
		enElevator(q, floor, 0);
	}
	else
		printf(">> �˿ͳ����ݡ�\n");
}

void enElevator(elevator* q, int x, int drct)
{
	if (q->front->floor == x) //Ӧ�Գ˿Ͱ�������¥������
	{
		alterpsg(q, x, drct);
		return;
	}
	task* nxt = q->front->next, * loc = NULL, * tmp = NULL;
	int flag = q->status; //(#)
	for (tmp = q->front; tmp != NULL; tmp = tmp->next)
	{
		if (tmp->floor == x)
		{
			if (tmp->flag == drct)
				return;
			else
			{
				loc = tmp;
				break;
			}
		}
		if (loc == NULL && nxt != NULL && (x > tmp->floor) == (x < nxt->floor) && drct * (tmp->floor > nxt->floor ? -1 : 1) >= 0)
			loc = tmp;
		else if (flag != 0 && loc == NULL && nxt != NULL && flag * (nxt->floor - tmp->floor) < 0 && (x - tmp->floor) * flag > 0) //(#)��һ���Ծ�������ͬ���Ŀ��¥��
			loc = tmp; 
		if (nxt != NULL)
		{
			flag = (nxt->floor > tmp->floor) ? 1 : -1; 
			nxt = nxt->next;
		}
	}
	task* tsk = initTask();
	tsk->floor = x;
	tsk->flag = drct;
	if (loc != NULL)
		insertTask(loc, tsk);
	else
		q->rear = q->rear->next = tsk;  //(*)�������������q->rear->next����Ϊ��

	//���·��
	printf("=> ���ݵ�·�߽���Ϊ��%d", q->front->floor);
	tmp = q->front->next;
	while (tmp != NULL)
	{
		printf("->%d", tmp->floor);
		tmp = tmp->next;
	}
	printf("\n");

	Sleep(ITVL_ELVT * 1000);
}

int front(elevator* q)
{
	if (!isEmpty(q))
		return q->front->next->floor;
	else
		return 0;
}

void* Animate(void* q)
{
	elevator* e = (elevator*)q;
	int cnt = 0;
	char c;
	while (1)
	{
		if (isEmpty(e))
		{
			e->status = 0;
			switch (cnt++)
			{
			case 0:
				printf("? ����ing~\n");
				break;
			case 1:
				printf("? ����ing~\n");
				break;
			case 2:
				printf("? ����ing~\n");
				break;
			case 3:
				printf("? ����ing~\n");
				cnt = 0;
				break;
			}
			Sleep(ITVL_ELVT * 2000);
			continue;
		}
		else
		{
			if (e->front->floor == front(e))
			{
				printf("�� �����ѵ�%d¥,����ing~\n", front(e));
				Sleep(ITVL_ELVT * 2000);
				deElevator(e);
			}
			else
			{
				int crt = e->front->floor, tgr = front(e);
				e->front->floor += (crt > tgr ? (e->status = -1) : (e->status = 1));
				switch (e->status)
				{
				case -1:
					printf("? ");
					break;
				case 1:
					printf("�� ");
					break;
				}
				printf("����Ŀǰ������%d¥��\n", e->front->floor);
				Sleep(ITVL_ELVT * 1000);
			}
		}
	}
}

void* psg(void* q)
{
	elevator* e = (elevator*)q;
	srand(time(0));
	while (1)
	{
		int opt = rand() % stories + 1;
		int time = rand() % MAXITVL_PSG;
		printf(">> %d¥�˿Ͱ�����", opt);
		switch (time % 2)
		{
		case 0:
			printf("����\n");
			break;
		case 1:
			printf("����\n");
			break;
		}
		enElevator(e, opt, 2 * (time % 2) - 1); //��0��1ӳ��Ϊ-1��1
		Sleep(time * 1000);
	}
}