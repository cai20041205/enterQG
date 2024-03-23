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
DuLNode* end;//β�ڵ�
int main() {
	DuLNode* L = NULL;
	menu_control(L);
	return 0;
}


void menu()
{
	printf("****************************\n");
	printf("**  1.��������           **\n");
	printf("**  2.��������           **\n");
	printf("**  3.��ӽ��(�ɲ�ͷ��β)**\n");
	printf("**  4.ɾ�����           **\n");
	printf("**  5.ͷ������         **\n");
	printf("**  6.β������         **\n");
	printf("**  7.��                 **\n");
	printf("**  8.��                 **\n");
	printf("**  9.�ݻ�����           **\n");
	printf("**  10.�˳�����           **\n");
	printf("****************************\n");
	printf("***********˫����***********\n");
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
		printf("\033[1;34;45m**  3.��ӽ��(�ɲ�ͷ��β)**\n\033[0m");
	if (line == 4)
		printf("\033[1;34;45m**  4.ɾ�����           **\n\033[0m");
	if (line == 5)
		printf("\033[1;34;45m**  5.ͷ������         **\n\n\033[0m");
	if (line == 6)
		printf("\033[1;34;45m**  6.β������         **\n\033[0m");
	if (line == 7)
		printf("\033[1;34;45m**  7.��                 **\n\033[0m");
	if (line == 8)
		printf("\033[1;34;45m**  7.��                 **\n\033[0m");
	if (line == 9)
		printf("\033[1;34;45m**  9.�ݻ�����           **\n\033[0m");
	if (line == 10)
		printf("\033[1;34;45m**  10.�˳�����           **\n\033[0m");
}


DuLNode* InitList() {
	printf("�������Ľ���Ӧ��dataֵΪ0,���ʼ������(����������0�Ľ��)\n");
	printf("�������1������Ӧ��dataֵ:");
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
		printf("�������%d������Ӧ��dataֵ:", n);
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
	printf("�����������������\n");
	DuLNode* temp = end;
	while (p != NULL)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
	printf("������-----\n");
	while (end != NULL)
	{
		printf("%d\n", end->data);
		end = end->prior;
	}
	end = temp;
}

DuLNode* InsertList(DuLNode* p, DuLNode* q) {
	printf("��������������Ҫ����������λ��(�ڼ������,���ܳ�������ܳ��ȼ�1,"
		"�ܽ�����Ϊ % d) :", n);
	int b;//��ʾ��ӵ�λ��
	DuLNode* head = p;
	scanf("%d", &b);
	while (b > n + 1)//n-2Ϊ����ܸ���
	{
		printf("��ӵ�λ�ó�������ܳ��ȼ�1,����������:");
		scanf("%d", &b);
	}
	int c = 1;
	if (b==1) {
		q->next = p;
		p->prior = q;
		q->prior = NULL;
		n++;
		printf("��ӳɹ�\n");
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
		printf("��ӳɹ�\n");
		return head;
	}
	else
	{
		p->next = q;
		q->prior = p;
		q->next = NULL;
		end = q;
		n++;
		printf("��ӳɹ�\n");
		return head;
	}
}

DuLNode* InsertBeforeList_DuL(DuLNode* p, DuLNode* q) {
	q->next = p;
	p->prior = q;
	q->prior = NULL;
	printf("��ӳɹ�\n");
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
	printf("��ӳɹ�\n");
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
	printf("����ݻٳɹ�\n");
}



void menu_control(DuLNode*L)
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
			if (t == 1)
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
			DuLNode* q = (DuLNode*)malloc(sizeof(DuLNode));
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
				DuLNode* p2 = L->next;
				p2->prior = NULL;
				free(L);
				L = p2;
				n--;
				printf("ɾ���ɹ�");
			}
			else if (end->data==m)
			{
				DuLNode* p2 = end->prior;
				end->prior->next = NULL;
				free(end);
				end = p2;
				n--;
				printf("ɾ���ɹ�");
			}
			else
			{
				int result = DeleteList(L, &m);
				if (result == SUCCESS)printf("ɾ���ɹ�");
				else printf("�����в�����������dataֵ,����ɾ��");
			}
			system("pause");
		}
		else if (line == 5)
		{
			system("cls");
			gotoxy(0, 0);
			DuLNode* q = (DuLNode*)malloc(sizeof(DuLNode));
			printf("������Ҫ��ӵĽ���dataֵ:");
			scanf("%d", &q->data);
			L = InsertBeforeList_DuL(L, q);
			system("pause");
		}
		else if (line == 6)
		{
			system("cls");
			gotoxy(0, 0);
			DuLNode* q = (DuLNode*)malloc(sizeof(DuLNode));
			printf("������Ҫ��ӵĽ���dataֵ:");
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

