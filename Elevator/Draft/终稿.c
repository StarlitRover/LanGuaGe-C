//Note:���и�仯�Ĳ��־��á��޶��������

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
//#include <easyx.h>
#include <Windows.h>
#include <time.h>
#include<math.h>
#define isEmpty(q) (q->front->next==NULL)
#define MAXITVL_PSG 20
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
	printf("��*��*��*��*��*��*��*��*��*��*��*��*��\n");
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
	//�޶���1:START
	int crt = q->front->floor;
	task* tmp = NULL;
	while (!isEmpty(q) && q->front->next->floor == crt)
	{
		tmp = q->front->next;
		q->front->next = tmp->next;

		if (tmp->next == NULL)
			q->rear = q->front; //֮���Բ����������if�Ƿ�ֹ��(*)�н�ֵ��ֵ��NULL

		alterpsg(q, tmp->floor, tmp->flag); //alterpsg�������ڵ���ifǰ����Ϊ(#)�е�flag���ǵ�
	}
	//END
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
	//�޶���2:START
	task* tmp = q->front, * loc = NULL;
	int flag = q->status, crt = q->front->floor;
	while (tmp != NULL)
	{
		if (tmp->floor == x)
		{
			if (drct == tmp->flag)
				return;
			else if (flag * drct < 0)
			{
				loc = tmp;
				break;
			}
			else
				break;
		}
		tmp = tmp->next;
	}
	tmp = q->front;
	if (loc == NULL)
	{
		if (flag * (x - crt) > 0 && drct * flag >= 0)
		{
			while (tmp->next != NULL && flag * tmp->next->floor >= flag * crt && flag * tmp->next->floor < flag * x && flag * tmp->next->flag >= 0)
				tmp = tmp->next;
		}
		else if (drct * flag <= 0)
		{
			while (tmp->next != NULL && flag * tmp->next->floor >= flag * crt && flag * tmp->next->flag >= 0)
				tmp = tmp->next;
			while (tmp->next != NULL && tmp->next->flag * flag <= 0 && flag * tmp->next->floor > flag * x)
				tmp = tmp->next;
		}
		else
		{
			while (tmp->next != NULL && flag * tmp->next->floor >= flag * crt && flag * tmp->next->flag >= 0)
				tmp = tmp->next;
			while (tmp->next != NULL && tmp->next->flag * flag <= 0)
				tmp = tmp->next;
			while (tmp->next != NULL && tmp->next->flag * flag >= 0 && flag * x > flag * tmp->next->floor)
				tmp = tmp->next;
		}
		loc = tmp;
	}
	//END
	task* tsk = initTask();
	tsk->floor = x;
	tsk->flag = drct;
	if (loc->next != NULL)
		insertTask(loc, tsk);
	else
		q->rear = q->rear->next = tsk;  //(*)�������������q->rear->next����Ϊ��

	//���·��
	printf("=> ���ݵ�·�߽���Ϊ��%d", q->front->floor);
	tmp = q->front->next;
	while (tmp != NULL)
	{
		printf("->%d", tmp->floor);
		if (tmp->flag == -1)
			printf("(��)");
		else if (tmp->flag == 1)
			printf("(��)");
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
				printf("�� ����ing~\n");
				break;
			case 1:
				printf("�� ����ing~\n");
				break;
			case 2:
				printf("�� ����ing~\n");
				break;
			case 3:
				printf("�� ����ing~\n");
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
					printf("�� ");
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