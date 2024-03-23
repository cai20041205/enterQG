#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include"duLinkedList.h"
#define upkey 72
#define downkey 80
#define leftkey 75
#define rightkey 77
extern void menu();
extern void HideCursor();
extern void gotoxy(int x, int y);
extern void show(int line);
extern void menu_control(DuLNode* L);
int n;
int t;
DuLNode* end;//尾节点
int main() {
	DuLNode* L = NULL;
	menu_control(L);
	return 0;
}


void menu()
{
	printf("****************************\n");
	printf("**  1.创建链表           **\n");
	printf("**  2.遍历链表           **\n");
	printf("**  3.添加结点(可插头或尾)**\n");
	printf("**  4.删除结点           **\n");
	printf("**  5.头插入结点         **\n");
	printf("**  6.尾插入结点         **\n");
	printf("**  7.无                 **\n");
	printf("**  8.无                 **\n");
	printf("**  9.摧毁链表           **\n");
	printf("**  10.退出程序           **\n");
	printf("****************************\n");
	printf("***********双链表***********\n");
}


void HideCursor()
{
	HANDLE fd = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cinfo;
	cinfo.bVisible = 0;
	cinfo.dwSize = 1;
	SetConsoleCursorInfo(fd, &cinfo);  // 隐藏/显示控制台光标
}

void gotoxy(int x, int y)
{
	COORD pos = { x,y }; // 设置显示的位置
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE); // 获取标准输出设备句柄
	SetConsoleCursorPosition(hOut, pos); //两个参数分别是指定哪个窗体，具体位置
}


void show(int line)
{
	gotoxy(0, 0);
	menu();
	gotoxy(0, line);  // 选中的高亮变色
	if (line == 1)
		printf("\033[1;34;45m**  1.创建链表           **\n\033[0m");
	if (line == 2)
		printf("\033[1;34;45m**  2.遍历链表           **\n\033[0m");
	if (line == 3)
		printf("\033[1;34;45m**  3.添加结点(可插头或尾)**\n\033[0m");
	if (line == 4)
		printf("\033[1;34;45m**  4.删除结点           **\n\033[0m");
	if (line == 5)
		printf("\033[1;34;45m**  5.头插入结点         **\n\n\033[0m");
	if (line == 6)
		printf("\033[1;34;45m**  6.尾插入结点         **\n\033[0m");
	if (line == 7)
		printf("\033[1;34;45m**  7.无                 **\n\033[0m");
	if (line == 8)
		printf("\033[1;34;45m**  7.无                 **\n\033[0m");
	if (line == 9)
		printf("\033[1;34;45m**  9.摧毁链表           **\n\033[0m");
	if (line == 10)
		printf("\033[1;34;45m**  10.退出程序           **\n\033[0m");
}


DuLNode* InitList() {
	printf("如果输入的结点对应的data值为0,则初始化结束(链表不包括有0的结点)\n");
	printf("请输入第1个结点对应的data值:");
	DuLNode* p = (DuLNode*)malloc(sizeof(DuLNode));
	scanf("%d", &p->data);
	DuLNode* p1 = p;
	DuLNode* head = NULL;
	n = 0;
	while (p->data != 0) {
		n++;
		if (head == NULL) {
			head = p;
		}
		else {
			p1->next = p;
			p->prior = p1;
		}
		p1 = p;
		p = (DuLNode*)malloc(sizeof(DuLNode));
		printf("请输入第%d个结点对应的data值:", n);
		scanf("%d", &p->data);
	}
	head->prior = NULL;
	p1->next = NULL;
	end = p1;
	t = 1;
	if (n <= 1)
	{
		return NULL;
	}
	else
	{
		return head;
	}
}

void ErgodicList(DuLNode* p) {
	printf("链表遍历正向结果如下\n");
	DuLNode* temp = end;
	while (p != NULL)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
	printf("反向结果-----\n");
	while (end != NULL)
	{
		printf("%d\n", end->data);
		end = end->prior;
	}
	end = temp;
}

DuLNode* InsertList(DuLNode* p, DuLNode* q) {
	printf("请输入这个结点需要添加在链表的位置(第几个结点,不能超过结点总长度加1,"
		"总结点个数为 % d) :", n);
	int b;//表示添加的位置
	DuLNode* head = p;
	scanf("%d", &b);
	while (b > n + 1)//n-2为结点总个数
	{
		printf("添加的位置超过结点总长度加1,请重新输入:");
		scanf("%d", &b);
	}
	int c = 1;
	if (b==1) {
		q->next = p;
		p->prior = q;
		q->prior = NULL;
		n++;
		printf("添加成功\n");
		return q;
	}
	while (p != NULL) {
		if (c == b - 1)break;
		c++;
		p = p->next;
	}
	if (p->next!=NULL)
	{
		q->next = p->next;
		p->next->prior = q;
		p->next = q;
		q->prior = p;
		n++;
		printf("添加成功\n");
		return head;
	}
	else
	{
		p->next = q;
		q->prior = p;
		q->next = NULL;
		end = q;
		n++;
		printf("添加成功\n");
		return head;
	}
}

DuLNode* InsertBeforeList_DuL(DuLNode* p, DuLNode* q) {
	q->next = p;
	p->prior = q;
	q->prior = NULL;
	printf("添加成功\n");
	n++;
	return q;
}

Status DeleteList(DuLNode* p, ElemType* e) {
	DuLNode* p1 = p;
	int sign = 0;
	p = p->next;
	while (p != NULL) {
		if (p->data == *e) {
			sign = 1;
			break;
		}
		p = p->next;
		p1 = p1->next;
	}
	if (sign == 0)
	{
		return FALT;
	}
	p1->next = p->next;
	p->next->prior = p1;
	free(p);
	n--;
	return SUCCESS;
}

DuLNode* InsertAfterList_DuL(DuLNode* p, DuLNode* q) {
	end->next = q;
	q->prior = end;
	q->next = NULL;
	n++;
	printf("添加成功\n");
	return q;
}



void DestroyList(DuLNode* L) {
	DuLNode* p = L;
	L = L->next;
	while (L->next != NULL) {
		free(p);
		p = L;
		L = L->next;
	}
	t = 0;
	free(L);
	printf("链表摧毁成功\n");
}



void menu_control(DuLNode*L)
{
	char c1, c2, ch;
	int line;

	while (1)
	{
		system("cls");   //系统清屏
		system("color 09");  //设置控制台的颜色
		Beep(2000, 250); //系统发声 
		HideCursor();    //隐藏光标
		menu(); //显示菜单
		line = 1;
		gotoxy(0, line); //移动光标到第一行的首位置
		printf("\033[1;34;45m**  1.创建链表           **\n\033[0m");
		for (; (c1 = _getch()) != '\r';)  // 读取按键值，遇到'\r'回车则结束
		{ //注意敲击箭头键会出现两个字符数据:
		  //LEFT(-32,75), UP(-32,72), DOWN(-32,80),Right(-32,77)
			if (c1 == -32)
			{
				c2 = _getch(); //获得按键的第二个键值，并根据方向选择菜单功能
				ch = c2;
				if (ch == upkey && line != 1)
				{
					line--;
					system("color 09");
					show(line);
					continue;
				}
				else if (ch == downkey && line != 10)
				{
					line++;
					system("color 09");
					show(line);
					continue;
				}
				else if (ch == upkey && line == 1)
				{
					line = 10;
					system("color 09");
					show(line);
					continue;
				}
				else if (ch == downkey && line == 10)
				{
					line = 1;
					system("color 09");
					show(line);
					continue;
				}
			}
		}

		if (line == 1)
		{
			system("cls");
			gotoxy(0, 0);
			if (t == 1)
			{
				printf("链表已存在\n");
			}
			else {
				while (1) {
					L = InitList();
					if (L != NULL) {
						printf("链表初始化成功\n");
						break;
					}
					else printf("链表结点数量少于2个,链表初始化失败,请重新初始化链表\n\n");
				}
			}

			system("pause");
		}
		else if (line == 2)
		{
			system("cls");
			gotoxy(0, 0);
			ErgodicList(L);
			system("pause");
		}
		else if (line == 3)
		{
			system("cls");
			gotoxy(0, 0);
			DuLNode* q = (DuLNode*)malloc(sizeof(DuLNode));
			printf("请输入要添加的结点的data值:");
			scanf("%d", &q->data);
			L=InsertList(L, q);
			system("pause");
		}
		else if (line == 4)
		{
			system("cls");
			gotoxy(0, 0);
			printf("请输入要删除的结点对应的data值:");
			int m;
			scanf("%d", &m);
			if (L->data == m)//如果删除的是第一个结点
			{
				DuLNode* p2 = L->next;
				p2->prior = NULL;
				free(L);
				L = p2;
				n--;
				printf("删除成功");
			}
			else if (end->data==m)
			{
				DuLNode* p2 = end->prior;
				end->prior->next = NULL;
				free(end);
				end = p2;
				n--;
				printf("删除成功");
			}
			else
			{
				int result = DeleteList(L, &m);
				if (result == SUCCESS)printf("删除成功");
				else printf("链表中不存在这样的data值,不用删除");
			}
			system("pause");
		}
		else if (line == 5)
		{
			system("cls");
			gotoxy(0, 0);
			DuLNode* q = (DuLNode*)malloc(sizeof(DuLNode));
			printf("请输入要添加的结点的data值:");
			scanf("%d", &q->data);
			L = InsertBeforeList_DuL(L, q);
			system("pause");
		}
		else if (line == 6)
		{
			system("cls");
			gotoxy(0, 0);
			DuLNode* q = (DuLNode*)malloc(sizeof(DuLNode));
			printf("请输入要添加的结点的data值:");
			scanf("%d", &q->data);
			end = InsertAfterList_DuL(end, q);
			system("pause");
		}
		else if (line == 7)
		{
			system("cls");
			gotoxy(0, 0);
			system("pause");
		}
		else if (line == 8)
		{
			system("cls");
			gotoxy(0, 0);
			system("pause");
		}
		else if (line == 9)
		{
			system("cls");
			gotoxy(0, 0);
			DestroyList(L);
			system("pause");
		}
		else if (line == 10)
		{
			system("cls");
			gotoxy(0, 0);
			exit(0);
		}

	}
}

