#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "linkedList.h"
#define upkey 72
#define downkey 80
#define leftkey 75
#define rightkey 77
extern void menu();
extern void HideCursor();
extern void gotoxy(int x, int y);
extern void show(int line);
extern void menu_control(LNode* L);
int n ;
int t=0;

int main() {
	LNode* L= NULL;
	menu_control(L);
	return 0;
}


void menu()
{
	printf("****************************\n");
	printf("**  1.��������           **\n");
	printf("**  2.��������           **\n");
	printf("**  3.��ӽ��           **\n");
	printf("**  4.ɾ�����           **\n");
	printf("**  5.��ת����           **\n");
	printf("**  6.�ҵ������е�       **\n");
	printf("**  7.������ż����       **\n");
	printf("**  8.�ж������Ƿ�ɻ�   **\n");
	printf("**  9.�ݻ�����           **\n");
	printf("**  10.�˳�����           **\n");
	printf("****************************\n");
	printf("***********������***********\n");
}


void HideCursor()
{
	HANDLE fd = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cinfo;
	cinfo.bVisible = 0;
	cinfo.dwSize = 1;
	SetConsoleCursorInfo(fd, &cinfo);  // ����/��ʾ����̨���
}

void gotoxy(int x, int y)
{
	COORD pos = { x,y }; // ������ʾ��λ��
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE); // ��ȡ��׼����豸���
	SetConsoleCursorPosition(hOut, pos); //���������ֱ���ָ���ĸ����壬����λ��
}


void show(int line)
{
	gotoxy(0, 0);
	menu();
	gotoxy(0, line);  // ѡ�еĸ�����ɫ
	if (line == 1)
		printf("\033[1;34;45m**  1.��������           **\n\033[0m");
	if (line == 2)
		printf("\033[1;34;45m**  2.��������           **\n\033[0m");
	if (line == 3)
		printf("\033[1;34;45m**  3.��ӽ��           **\n\033[0m");
	if (line == 4)
		printf("\033[1;34;45m**  4.ɾ�����           **\n\033[0m");
	if (line == 5)
		printf("\033[1;34;45m**  5.��ת����           **\n\n\033[0m");
	if (line == 6)
		printf("\033[1;34;45m**  6.�ҵ������е�       **\n\033[0m");
	if (line == 7)
		printf("\033[1;34;45m**  7.������ż����       **\n\033[0m");
	if (line == 8)
		printf("\033[1;34;45m**  8.�ж������Ƿ�ɻ�   **\n\033[0m");
	if (line == 9)
		printf("\033[1;34;45m**  9.�ݻ�����           **\n\033[0m");
	if (line == 10)
		printf("\033[1;34;45m**  10.�˳�����           **\n\033[0m");
}


LNode* InitList() {
	printf("�������Ľ���Ӧ��dataֵΪ0,���ʼ������(����������0�Ľ��)\n");
	printf("�������1������Ӧ��dataֵ:");
	LNode* p = (LNode*)malloc(sizeof(LNode));
	scanf("%d",&p->data); 
	LNode* p1 =p;
	LNode* head=NULL;
	n = 0;
	while (p->data != 0) {
		n++;
		if (head == NULL) {
			head = p;
		}
		else p1->next = p;
		p1 = p;
		 p = (LNode*)malloc(sizeof(LNode));
		 printf("�������%d������Ӧ��dataֵ:",n);
		 scanf("%d", &p->data);
	}
	p1->next = NULL;
	t = 1;
	if (n<=1)
	{
		return NULL;
	}
	else
	{
		return head;
	}
	
}

void ErgodicList(LNode* p) {
	printf("��������������\n");
	while (p!=NULL)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
}

LNode* InsertList(LNode* p, LNode* q) {
	printf("��������������Ҫ����������λ��(�ڼ������,���ܳ�������ܳ��ȼ�1,"
		"�ܽ�����Ϊ % d) :",n);
    int b;//��ʾ��ӵ�λ��
	LNode* head = p;
	scanf("%d", &b);
	while (b>n+1)//n-2Ϊ����ܸ���
	{
		printf("��ӵ�λ�ó�������ܳ��ȼ�1,����������:");
		scanf("%d", &b);
	}
	int c=1;
	if (b==1)
	{
		q->next = p;
		printf("��ӳɹ�");
		return q;
	}
	while (p != NULL) {
		if (c == b - 1)break;
		c++;
		p = p->next;
	}
	q->next = p->next;
	p->next = q;
	n++;
	printf("��ӳɹ�");
	return head;
}

Status DeleteList(LNode* p, ElemType* e) {
	LNode* p1=p;
	int sign=0;
	p = p->next;
	while (p!=NULL) {
		if (p->data == *e) {
			sign = 1;
			break;
		}
		p = p->next;
		p1 = p1->next;
	}
	if (sign==0)
	{
		return FALT;
	}
    p1->next = p->next;
	free(p);
	n--;
	return SUCCESS;
}

LNode* ReverseList(LNode* p) {
	
	LNode* head = p;
	LNode* q1 = p;
	while (q1->next!=NULL)
	{
		LNode* q2 = q1->next;
		q1->next = q2->next;
		q2->next = head;
		head = q2;
		q2 = q1;
	}
	return head;
}

LNode* FindMidNode(LNode* L) {
	LNode* p1 = L, * p2 = L;
	while ((p2 != NULL)&& (p2->next != NULL)) {
		p1 = p1->next;
		p2 = p2->next->next;
	}
	return p1;
}

void DestroyList(LNode* L) {
	LNode* p = L;
	L = L->next;
	while (L->next!=NULL) {
		free(p);
		p = L;
		L = L->next;
	}
	t = 0;
	free(L); 
	
	printf("����ݻٳɹ�\n");
}

Status IsLoopList(LNode* L) {
	LNode* p1 = L, * p2 = L;
	
	while ((p2 != NULL) && (p2->next != NULL)) {
		p1 = p1->next;
		p2 = p2->next->next;
		if (p1 == p2) {
			return SUCCESS;
		}
	}
	return FALT;
}

LNode* ReverseEvenList(LNode* L) {
	if (L->next->next==NULL)
	{
		LNode* p = L->next;
		p->next = L;
		L->next = NULL;
		return p;
	}
	LNode* p1 = L, *p5,
		* p2 = L->next, 
		* p3 = L->next->next, 
		* p4 = L->next->next->next;
	p2->next = p1;
	p1->next = p3;
	LNode* head = p2;
	while (p4!=NULL) {
		p5 = p1;
		p1 = p3;
		p2 = p4;
		if (p4->next == NULL|| p4->next->next == NULL) {
			p2->next = p1;
			p5->next = p2;
			p1->next = NULL; 
			return head;
		}
		else
		{
			p3 = p4->next;
			p4 = p4->next->next;
			p2->next = p1;
			p1->next = p3;
			p5->next = p2;
		}
	}
	return head;
}

void menu_control(LNode* L)
{
	char c1, c2, ch;
	int line;


	while (1)
	{
		system("cls");   //ϵͳ����
		system("color 09");  //���ÿ���̨����ɫ
		Beep(2000, 250); //ϵͳ���� 
		HideCursor();    //���ع��
		menu(); //��ʾ�˵�
		line = 1;
		gotoxy(0, line); //�ƶ���굽��һ�е���λ��
		printf("\033[1;34;45m**  1.��������           **\n\033[0m");
		for (; (c1 = _getch()) != '\r';)  // ��ȡ����ֵ������'\r'�س������
		{ //ע���û���ͷ������������ַ�����:
		  //LEFT(-32,75), UP(-32,72), DOWN(-32,80),Right(-32,77)
			if (c1 == -32)
			{
				c2 = _getch(); //��ð����ĵڶ�����ֵ�������ݷ���ѡ��˵�����
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
				if (t==1)
				{
					printf("�����Ѵ���\n");
				}
				else {
					while (1) {
						L = InitList();
						if (L != NULL) {
							printf("�����ʼ���ɹ�\n");
							break;
						}
						else printf("��������������2��,�����ʼ��ʧ��,�����³�ʼ������\n\n");
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
				LNode* q = (LNode*)malloc(sizeof(LNode));
				printf("������Ҫ��ӵĽ���dataֵ:");
				scanf("%d", &q->data);
				L=InsertList(L, q);
				system("pause");
			}
			else if (line == 4)
			{
				system("cls");
				gotoxy(0, 0);
				printf("������Ҫɾ���Ľ���Ӧ��dataֵ:");
				int m;
				scanf("%d", &m);
				if (L->data == m)//���ɾ�����ǵ�һ�����
				{	
					LNode* p2 = L->next;
					free(L);
					L = p2;
					n--;
					printf("ɾ���ɹ�\n");
				}
				else
				{
					int result = DeleteList(L, &m);
					if (result == SUCCESS)printf("ɾ���ɹ�\n");
					else printf("�����в�����������dataֵ,����ɾ��\n");
				}
				system("pause");
			}
			else if (line == 5)
			{
				system("cls");
				gotoxy(0, 0);
				L=ReverseList(L);
				printf("��ת�ɹ�\n");
				system("pause");
			}
			else if (line == 6)
			{
				system("cls");
				gotoxy(0, 0);
				printf("�м����Ӧ��dataֵΪ%d\n", FindMidNode(L)->data);
				system("pause");
			}
			else if (line == 7)
			{
				system("cls");
				gotoxy(0, 0);
				//exit(0);
				L=ReverseEvenList(L);
				system("pause");
			}
			else if (line == 8)
			{
				system("cls");
				gotoxy(0, 0);
				int result=IsLoopList(L);
				if (result==SUCCESS){
					printf("����ɻ�\n");
				}
				else printf("�����ɻ�\n");
				system("pause");
			}
			else if (line == 9)
			{
				system("cls");
				gotoxy(0, 0);
				//exit(0);
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







