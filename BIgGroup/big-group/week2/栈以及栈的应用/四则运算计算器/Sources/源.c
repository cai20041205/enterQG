#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <stdbool.h>
typedef  struct StackNode
{
	char data;
	struct StackNode* next;
}StackNode, * LinkStackPtr;

typedef  struct StackNode1
{
	double data1;
	struct StackNode1* next;
}StackNode1, * LinkStackPtr1;

typedef  struct  LinkStack
{
	LinkStackPtr top; //ջ��ָ��
	int	count;//ջ��Ԫ�ظ���
}LinkStack;

typedef  struct  LinkStack1
{
	LinkStackPtr1 top; //ջ��ָ��
	int	count;//ջ��Ԫ�ظ���
}LinkStack1;

void operation(LinkStack1*s,char c) {//���㷨��
	StackNode1* temp = s->top;
	s->top = s->top->next;
	if (c=='+')
	{	
		s->top->data1 = temp->data1 + s->top->data1;
	
	}
	else if(c=='-')
	{		
		s->top->data1 =  s->top->data1- temp->data1 ;
		
	}
	else if (c=='*')
	{		
		s->top->data1 = s->top->data1 * temp->data1;
		
	}
	else if (c == '/') {	
		s->top->data1 = s->top->data1 / temp->data1;
		
	}	
	free(temp);
}

int isture(char c[]) {
	if (c[(strlen(c) - 1)] !=')' &&( c[(strlen(c) - 1)]<48 || c[(strlen(c) - 1)]>57))
	{
		return -1;
	}
	if (c[0] != '(' && (c[0] < 48 || c[0]>57)&& c[0] != '-')
	{
		return -1;
	}
	int sign1=0, sign2=0;
	int sign3 = 0,sign4=0;
	for (int i = 0; i < strlen(c); i++)
	{
		if (c[i]=='/'&&c[i+1]=='0')
		{
			return -1;
		}
		if (c[i] >= 48 && c[i]<=57)
		{
			sign4 = 1;
		}
		if (c[i] == '(') {
			sign1++;
			sign3 = 1;
		}
		if (c[i]==')')
		{
			sign2++;
			sign3 = 0;
		}
		if ((c[i] == '+' || c[i] == '-' || c[i] == '*' || c[i] == '/')&& (c[i+1] == '+' || c[i+1] == '-' || c[i+1] == '*' || c[i+1] == '/'))
		{
			return -1;
		}
		if (c[i] != '+' && c[i] != '-' && c[i] != '*' && c[i] != '/' && (c[i] < 48 || c[i]>57)&&c[i]!='('&&c[i]!=')') return -1;
	}
	if (sign1!=sign2||sign3==1||sign4==0)
	{
		return -1;
	}
	return 1;
}
void calc() {
	char a[40] = { '\0' };
	char b[40] = { '\0' };
	printf("������Ҫ�����ʽ��:");
	while (1)
	{
		gets(a);
		int sign = isture(a);
		if (sign == 1)
		{
			break;
		}
		printf("��������,����������:");
	}
	LinkStack* s = (LinkStack*)malloc(sizeof(LinkStack));
	s->top = NULL;
	s->count = 0;
	int j = 0;
	for (int i = 0; i < strlen(a); i++) {
		if (a[i] >= 48 && a[i] <= 57)//���֣�ֱ�����.
		{
			if (i >= 2 && a[i - 2] == '(' && (a[i - 1] == '-'))
			{
				b[j] = a[i];
				j++;
			}
			else if (j >= 1 && b[j - 1] == '-' && j - 1 == 0)
			{
				b[j] = a[i];
				j++;
			}
			else if (j >= 1 && (b[j - 1] == '+' || b[j - 1] == '-' || b[j - 1] == '*' || b[j - 1] == '/'))
			{
				b[j] = ' ';
				j++;
				b[j] = a[i];
				j++;
			}
			else
			{
				b[j] = a[i];
				j++;
			}

		}
		else if (i == 0 && a[i] == '-')
		{
			b[j] = a[i];
			j++;
			continue;
		}
		else if (s->count == 0 && a[i] == '-')
		{
			b[j] = ' ';
			j++;
			StackNode* node = (StackNode*)malloc(sizeof(StackNode));
			s->count++;
			node->data = a[i];
			node->next = NULL;
			s->top = node;
		}
		else if (s->count == 0 && a[i] != '-')
		{
			b[j] = ' ';
			j++;
			StackNode* node = (StackNode*)malloc(sizeof(StackNode));
			s->count++;
			node->data = a[i];
			node->next = NULL;
			s->top = node;
		}
		else if (a[i] == '(') //�����ţ�ֱ����ջ
		{
			StackNode* node = (StackNode*)malloc(sizeof(StackNode));
			s->count++;
			node->data = a[i];
			node->next = s->top;
			s->top = node;
			if (a[i + 1] == '-')
			{
				b[j] = a[i + 1];
				i++;
				j++;
			}
		}
		/* if (���ȼ�����ջ������� ||
			ջ��Ϊ������)   ��ջ��
		else
		{
			ջ�����������ջ��
				�����Ƚ��µ�ջ�������(һֱ�ݹ���ȥ) ֱ����ǰ���������ջ�������Ϊֹ��
				��󽫵�ǰ�������ջ��
		}*/
		else if (a[i] == '+' || a[i] == '-')
		{
			if (s->top->data == '*' || s->top->data == '/')
			{
				b[j] = ' ';
				j++;
				StackNode* temp = s->top;
				b[j] = s->top->data;
				j++;
				s->top = s->top->next;
				free(temp);
				s->count--;
			}
			if (s->top->data == '+' || s->top->data == '-')
			{
				b[j] = ' ';
				j++;
				b[j] = s->top->data;
				j++;
				s->top->data = a[i];
			}
			else if (s->top->data = '(')
			{
				b[j] = ' ';
				j++;
				StackNode* node = (StackNode*)malloc(sizeof(StackNode));
				s->count++;
				node->data = a[i];
				node->next = s->top;
				s->top = node;
			}

		}
		else if (a[i] == '*' || a[i] == '/')
		{

			if (s->top->data == '+' || s->top->data == '-')
			{
				b[j] = ' ';
				j++;
				StackNode* node = (StackNode*)malloc(sizeof(StackNode));
				node->data = a[i];
				node->next = s->top;
				s->top = node;
				s->count++;
			}
			else if (s->top->data == '*' || s->top->data == '/')
			{
				b[j] = ' ';
				j++;
				b[j] = s->top->data;
				j++;
				s->top->data = a[i];
			}
			else if (s->top->data = '(')
			{
				b[j] = ' ';
				j++;
				StackNode* node = (StackNode*)malloc(sizeof(StackNode));
				s->count++;
				node->data = a[i];
				node->next = s->top;
				s->top = node;
			}

		}
		else if (a[i] == ')')//�����ţ���ջ�����������ջ����ջ�ٳ�ջ��ֱ�������š����Ų������
		{
			while (s->top->data != '(')
			{
				b[j] = ' ';
				j++;
				StackNode* temp = s->top;
				b[j] = s->top->data;
				j++;
				s->top = s->top->next;
				free(temp);
				s->count--;
			}
			StackNode* temp = s->top;
			s->top = s->top->next;
			free(temp);
			s->count--;
		}
	}
	while (s->count != 0)//����ʱ��ջʣ�����ݳ�ջ����Ϊֹ
	{
		b[j] = ' ';
		j++;
		StackNode* temp = s->top;
		b[j] = s->top->data;
		j++;
		s->top = s->top->next;
		free(temp);
		s->count--;
	}
	printf("%s\n", b);
	LinkStack1* s1 = (LinkStack1*)malloc(sizeof(LinkStack1));
	s1->top = NULL;
	for (int i = 0; i < strlen(b); i++)
	{
		if (b[i] == ' ')
		{
			continue;
		}
		if (b[i] == '+')
		{
			operation(s1, b[i]);
			continue;
		}
		if (b[i] == '-' && b[i + 1] == ' ')
		{
			operation(s1, b[i]);
			continue;
		}
		if (b[i] == '-' && b[i + 1] != ' ') {
			continue;
		}
		if (b[i] == '*')
		{
			operation(s1, b[i]);
			continue;
		}
		if (b[i] == '/')
		{
			operation(s1, b[i]);
			continue;
		}
		double temp;
		if (b[i] >= 48 && b[i] <= 57)
		{
			temp = b[i] - 48;
		}
		while (b[i] >= 48 && b[i] <= 57)
		{
			if (b[i + 1] != ' ')
			{
				temp = temp * 10 + (b[i + 1] - 48);
			}
			else
			{
				break;
			}
			i++;
		}
		if (b[i - 1] == '-')
		{
			temp = temp * (-1);
		}
		StackNode1* node = (StackNode1*)malloc(sizeof(StackNode1));
		node->data1 = temp;
		node->next = s1->top;
		s1->top = node;
	}
	if (b[strlen(b) - 1] == '-')
	{
		StackNode1* temp = s1->top;
		s1->top = s1->top->next;
		s1->top->data1 = s1->top->data1 - temp->data1;
		free(temp);
	}
	printf("%f\n", s1->top->data1);
}
void menu() {
	printf("1.����\n");
	printf("2.�˳�\n");
}
void menu_control() {
	while (1)
	{
		system("cls");
		menu();
		printf("��������Ҫѡ��Ĺ��ܵı��:");
		bool validInput = false;
		int number;
		while (!validInput) {
			int result = scanf("%d", &number);
			if (result == 1 && number > 0 && number < 3) {
				validInput = true;
				getchar();
				printf("����ɹ�\n");
			}
			else {
				printf("����Ĳ�����Ч�����������������롣\n");
				// ������뻺����
				int c;
				while ((c = getchar()) != '\n' && c != EOF);
			}
		}
		switch (number) {
		case 1: {
			system("cls");   // ����
			calc();
			system("pause");
			break;
		}
		case 2: {
			exit(0);
			break;
		}
		}
	}
}
int main()
{
	menu_control();
}
