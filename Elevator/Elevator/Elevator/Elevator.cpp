#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <easyx.h>
#include <time.h>
#include<math.h>
#define isEmpty(q) (q->front->next==NULL)
#define MAXITVL_PSG 40
#define ITVL_ELVT 0.5
#define TEXTX 590
#define OFFSET_TEXTY 20
#define FLOORX 235
#define FLOORY 40

int stories, texty = 50, idx = 0;
TCHAR str[40];
TCHAR flr[5];

DWORD WINAPI Animate(LPVOID q);
DWORD WINAPI psg(LPVOID q);
void predraw(int floor);
void openDoor();

typedef struct task
{
	int floor, flag;
	struct task* next;
}task;
task* initTask();
void insertTask(task* pre, task* tsk);

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

void drawFloor(int floor, int flag);
void partClear(int flag);
void writedown(TCHAR* str);

int main()
{
	int crt;
	printf("请设置总楼层数：\n");
	scanf("%d", &stories);
	while (stories < 1 || stories >= 1000)
	{
		printf("你想逃离地球？请重新输入（1-999）：\n");
		scanf("%d", &stories);
	}
	printf("请设置当前电梯所在楼层：\n");
	scanf("%d", &crt);
	while (crt<1 || crt>stories)
	{
		printf("咳咳…你把电梯安在外面了，请重新输入：\n");
		scanf("%d", &crt);
	}

	predraw(crt);

	elevator* e = initElevator();
	e->front->floor = crt;
	CreateThread(NULL, 0, Animate, (LPVOID)e, 0, NULL);
	Sleep(2000);
	CreateThread(NULL, 0, psg, (LPVOID)e, 0, NULL);
	while (1)
		Sleep(60000);
	closegraph();
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

	int crt = q->front->floor;
	task* tmp = NULL;
	while (!isEmpty(q) && q->front->next->floor == crt)
	{
		tmp = q->front->next;
		q->front->next = tmp->next;

		if (tmp->next == NULL)
			q->rear = q->front; //之所以不并到下面的if是防止在(*)中将值赋值给NULL

		alterpsg(q, tmp->floor, tmp->flag); //alterpsg函数放在调到if前面是为(#)中的flag考虑的
	}

	if (tmp->next == NULL)
		q->status = 0;
	else
		q->status = (q->front->floor > q->front->next->floor ? -1 : 1);

	free(tmp);
}

void alterpsg(elevator* q, int floor, int flag)
{
	if (flag != 0)
	{
		int preflr = floor;
		srand(time(0));
		if (flag == 1 && stories != floor)
			floor += (rand() % (stories - floor) + 1);
		else
			floor -= (rand() % floor);
		_stprintf(str, _T(">> %d楼乘客进入电梯，并按下了%d楼键"), preflr, floor);
		writedown(str);
		enElevator(q, floor, 0);
	}
	else
	{
		_stprintf(str, _T(">> 乘客出电梯"));
		writedown(str);
	}
}

void enElevator(elevator* q, int x, int drct)
{
	if (q->front->floor == x) //应对乘客按下所在楼层的情况
	{
		alterpsg(q, x, drct);
		return;
	}
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
	task* tsk = initTask();
	tsk->floor = x;
	tsk->flag = drct;
	if (loc->next != NULL)
		insertTask(loc, tsk);
	else
		q->rear = q->rear->next = tsk;  //(*)：如果不做处理q->rear->next可能为负

	//输出路线
	/*printf("=> 电梯的路线将变为：%d", q->front->floor);
	tmp = q->front->next;
	while (tmp != NULL)
	{
		printf("->%d", tmp->floor);
		tmp = tmp->next;
	}
	printf("\n");

	Sleep(ITVL_ELVT * 1000);*/
}

int front(elevator* q)
{
	if (!isEmpty(q))
		return q->front->next->floor;
	else
		return 0;
}

DWORD WINAPI Animate(LPVOID q)
{
	elevator* e = (elevator*)q;
	int sign = 1;
	while (1)
	{
		if (isEmpty(e))
		{
			if (sign)
			{
				e->status = sign = 0;
				_stprintf(str, _T("? 空闲ing~"));
				drawFloor(e->front->floor, 0);
				writedown(str);
			}
			Sleep(ITVL_ELVT * 1000);
			continue;
		}
		else
		{
			sign = 1;
			if (e->front->floor == front(e))
			{
				_stprintf(str, _T("◆ 电梯已到%d楼,开门ing~"), front(e));
				writedown(str);
				openDoor();
				Sleep(ITVL_ELVT * 2000);
				deElevator(e);
			}
			else
			{
				int crt = e->front->floor, tgr = front(e);
				e->front->floor += (crt > tgr ? (e->status = -1) : (e->status = 1));
				drawFloor(e->front->floor, e->status);
				Sleep(ITVL_ELVT * 1000);
			}
		}
	}
}

DWORD WINAPI psg(LPVOID q)
{
	elevator* e = (elevator*)q;
	srand(time(0));
	while (1)
	{
		int opt = rand() % stories + 1;
		int time = rand() % MAXITVL_PSG;
		switch (time % 2)
		{
		case 0:
			_stprintf(str, _T(">> %d楼乘客按下了↓键"), opt);
			break;
		case 1:
			_stprintf(str, _T(">> %d楼乘客按下了↑键"), opt);
			break;
		}
		writedown(str);
		enElevator(e, opt, 2 * (time % 2) - 1); //将0，1映射为-1，1
		Sleep(time * 1000);
	}
}

void predraw(int floor)
{
	initgraph(1000, 700);
	setbkcolor(RGB(208, 200, 174));
	cleardevice();
	setlinecolor(BLUE);
	setlinestyle(PS_DASHDOT, 2);
	rectangle(580, 40, 980, 680);
	setlinestyle(PS_SOLID, 3);
	setfillcolor(RGB(128, 128, 128));
	settextcolor(BLACK);
	settextstyle(20, 0, _T("楷体"));
	outtextxy(690, 10, _T("$电梯活动监视记录$"));
	rectangle(180, 35, 400, 110);
	fillrectangle(50, 150, 290, 650);
	fillrectangle(290, 150, 530, 650);
	_stprintf(flr, _T("≡   %d  "), floor);
	settextstyle(60, 0, _T("Candara"));
	outtextxy(FLOORX, FLOORY, flr);
}

void openDoor()
{
	int left = 290, right = 290, delta = 7;
	BeginBatchDraw();
	while (left > 50)
	{
		left -= delta;
		right += delta;
		partClear(1);
		fillrectangle(50, 150, left, 650);
		fillrectangle(right, 150, 530, 650);
		FlushBatchDraw();
		Sleep(ITVL_ELVT * 100);
	}
	Sleep(ITVL_ELVT * 1000);
	while (left < 290)
	{
		left += delta;
		right -= delta;
		partClear(1);
		fillrectangle(50, 150, left, 650);
		fillrectangle(right, 150, 530, 650);
		FlushBatchDraw();
		Sleep(ITVL_ELVT * 100);
	}
	EndBatchDraw();
}

void drawFloor(int floor, int flag)
{
	switch (flag)
	{
	case -1:
		_stprintf(flr, _T("?   %d  "), floor);
		break;
	case 0:
		_stprintf(flr, _T("≡   %d  "), floor);
		break;
	case 1:
		_stprintf(flr, _T("▲   %d  "), floor);
		break;
	}
	while (idx)
		Sleep(100);
	settextstyle(60, 0, _T("Candara"));
	outtextxy(FLOORX, FLOORY, flr);
}

void partClear(int flag)
{
	idx = 1;
	HRGN rgn = NULL;
	switch (flag)
	{
		/*case 0:
			rgn = CreateRectRgn(181, 36, 399, 109);
			break;*/
	case 1:
		rgn = CreateRectRgn(49, 149, 531, 651);
		break;
	case 2:
		rgn = CreateRectRgn(581, 41, 979, 679);
		break;
	}
	setcliprgn(rgn);
	clearcliprgn();
	setcliprgn(NULL);
	idx = 0;
}

void writedown(TCHAR* str)
{
	if (texty == 50)
		partClear(2);
	while (idx)
		Sleep(100);
	settextstyle(20, 0, _T("楷体"));
	outtextxy(TEXTX, texty, str);
	if ((texty += OFFSET_TEXTY) == 670)
		texty = 50;
}