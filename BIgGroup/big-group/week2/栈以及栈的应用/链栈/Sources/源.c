#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"
#include <stdbool.h>
int sign = 0;
void menu()
{
    printf("************************\n");
    printf("**  1.��ʼ��ջ        **\n");
    printf("**  2.�ж�ջ�Ƿ�Ϊ��  **\n");
    printf("**  3.�õ�ջ��Ԫ��    **\n");
    printf("**  4.���ջ          **\n");
    printf("**  5.����ջ          **\n");
    printf("**  6.���ջ����      **\n");
    printf("**  7.��ջ            **\n");
    printf("**  8.��ջ            **\n");
    printf("**  9.�˳�����        **\n");
    printf("************************\n");
}
Status isEmptyLStack(LinkStack* s) {
    //�ж�ջ�Ƿ�Ϊ��
    if (s==NULL)
    {
        return ERROR;
    }
    else
    {
        if (s->count!=0)
        {
            printf("ջ��Ϊ��\n");
        }
        else {
            printf("ջΪ��\n");
        }
    }
    return SUCCESS;
}
LinkStack* initLStack() {
    LinkStack* s = (LinkStack*)malloc(sizeof(LinkStack));
    s->top = NULL; // ��ʼ��ջ��ָ��ΪNULL
    s->count = 0;
    return s;
}
Status pushLStack(LinkStack* s, ElemType data) {
    if (s==NULL)
    {
        return ERROR;
    }
    s->count++;
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    node->data = data;
    node->next = s->top;
    s->top = node;
    printf("��ջ�ɹ�\n");
    return SUCCESS;
}
Status getTopLStack(LinkStack* s) {
    if (s == NULL)
    {
        printf("ջ������\n");
        return ERROR;
    }
    if (s->top == NULL)
    {
        printf("ջΪ��,��ջ��Ԫ��\n");
        return ERROR;
    }
    printf("ջ��Ԫ�ص�dataֵΪ%d\n", s->top->data);
    return SUCCESS;
}
Status clearLStack(LinkStack* s) {
    if (s == NULL)
    {
        printf("ջ������\n");
        return ERROR;
    }
    if (s->count==0)
    {
        printf("ջ�Ѿ��ǿյ�\n");
        return ERROR;
    }
    while (s->top->next!=NULL)
    {
        StackNode* temp = s->top;
        s->top = s->top->next;  
        free(temp);
    }
    free(s->top);
    printf("ջ�����\n");
    s->top = NULL;
    s->count = 0;
    return SUCCESS;
}
Status destroyLStack(LinkStack** s) {
    clearLStack(*s);
    free(*s);
    *s = NULL;
    printf("ջ�Ѵݻ�\n");
    sign = 0;
    return SUCCESS;
}
Status LStackLength(LinkStack* s, int* length) {
    if (s == NULL)
    {
        printf("ջ������\n");
        return ERROR;
    }
    *length = s->count;
    return SUCCESS;
}
Status popLStack(LinkStack* s, ElemType* data) {
    if (s == NULL)
    {
        printf("ջ������\n");
        return ERROR;
    }
    if (s->top == NULL)
    {
        printf("ջΪ��\n");
        return ERROR;
    }
    if (s->count==1)
    {
        *data = s->top->data;
        free(s->top);
        s->top = NULL;
        s->count--;
    }
    else
    {
        *data = s->top->data;
         StackNode * temp = s->top;
        s->top = s->top->next;
        free(temp);
        s->count--;
    }
    return SUCCESS;
}
void menu_control(LinkStack* s) {
    while (1) {
        system("cls");
        menu();
        printf("��������Ҫѡ��Ĺ��ܵı��:");        		
        bool validInput = false;
        int number;
        while (!validInput) {            
            int result = scanf("%d", &number);
            if (result == 1&&number>0&&number<10) {            
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
                if (sign==0)
                {
                    s = initLStack(); 
                    sign = 1;
                    printf("ջ��ʼ���ɹ�\n");
                }
                else {
                    printf("ջ�Ѿ���ʼ��\n");
                }
                system("pause");
                break;
            }
            case 2: {
            // ʵ���ж�ջ�Ƿ�Ϊ�յĹ���
                system("cls");
                int sign = isEmptyLStack(s);
                if (sign==ERROR)
                {
                    printf("ջ������\n");
                }
                system("pause");
                 break;
            }
            case 3: {
                // �õ�ջ��Ԫ��
                system("cls");
                 getTopLStack(s);
                system("pause");
                break;
            }
            case 4: {
                system("cls");
               clearLStack(s);
                system("pause");
                break;
            }
            case 5: {
                system("cls");
                destroyLStack(&s);
                system("pause");
                break;
            }
            case 6: {
                int length;
                system("cls");
                int sign=LStackLength(s, &length);
                if (sign==SUCCESS)
                {
                    printf("ջ����Ϊ%d\n", length);
                }
                system("pause");
                break;
            }
            case 7: {
                system("cls");
                bool validInput = false;
                int number;
                while (!validInput) {
	                printf("��������ջ�Ľ���Ӧ��dataֵ(��Ҫ������): ");
	                int result = scanf("%d", &number);
	                if (result == 1) {
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
                int sign = pushLStack(s, number);
                if (sign == ERROR)
                {
                    printf("ջ������,�޷���ջ\n");
                }
                system("pause");
                break;
            }
            case 8: {
                system("cls");
                int data;
                int sign=popLStack(s, &data);
                if (sign==SUCCESS)
                {
                    printf("�ѳ�ջ,��ֵΪ%d\n",data);
                }
                system("pause");
                break;
            }
            case 9: {
                exit(0);
            }
        }
    }
}

int main() {
    LinkStack* s = NULL;
    menu_control(s);
    return 0;
}
