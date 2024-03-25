#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"
#include <stdbool.h>
int sign = 0;
void menu()
{
    printf("************************\n");
    printf("**  1.初始化栈        **\n");
    printf("**  2.判断栈是否为空  **\n");
    printf("**  3.得到栈顶元素    **\n");
    printf("**  4.清空栈          **\n");
    printf("**  5.销毁栈          **\n");
    printf("**  6.检测栈长度      **\n");
    printf("**  7.入栈            **\n");
    printf("**  8.出栈            **\n");
    printf("**  9.退出程序        **\n");
    printf("************************\n");
}
Status isEmptyLStack(LinkStack* s) {
    //判断栈是否为空
    if (s==NULL)
    {
        return ERROR;
    }
    else
    {
        if (s->count!=0)
        {
            printf("栈不为空\n");
        }
        else {
            printf("栈为空\n");
        }
    }
    return SUCCESS;
}
LinkStack* initLStack() {
    LinkStack* s = (LinkStack*)malloc(sizeof(LinkStack));
    s->top = NULL; // 初始化栈顶指针为NULL
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
    printf("入栈成功\n");
    return SUCCESS;
}
Status getTopLStack(LinkStack* s) {
    if (s == NULL)
    {
        printf("栈不存在\n");
        return ERROR;
    }
    if (s->top == NULL)
    {
        printf("栈为空,无栈顶元素\n");
        return ERROR;
    }
    printf("栈顶元素的data值为%d\n", s->top->data);
    return SUCCESS;
}
Status clearLStack(LinkStack* s) {
    if (s == NULL)
    {
        printf("栈不存在\n");
        return ERROR;
    }
    if (s->count==0)
    {
        printf("栈已经是空的\n");
        return ERROR;
    }
    while (s->top->next!=NULL)
    {
        StackNode* temp = s->top;
        s->top = s->top->next;  
        free(temp);
    }
    free(s->top);
    printf("栈已清空\n");
    s->top = NULL;
    s->count = 0;
    return SUCCESS;
}
Status destroyLStack(LinkStack** s) {
    clearLStack(*s);
    free(*s);
    *s = NULL;
    printf("栈已摧毁\n");
    sign = 0;
    return SUCCESS;
}
Status LStackLength(LinkStack* s, int* length) {
    if (s == NULL)
    {
        printf("栈不存在\n");
        return ERROR;
    }
    *length = s->count;
    return SUCCESS;
}
Status popLStack(LinkStack* s, ElemType* data) {
    if (s == NULL)
    {
        printf("栈不存在\n");
        return ERROR;
    }
    if (s->top == NULL)
    {
        printf("栈为空\n");
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
        printf("请输入你要选择的功能的编号:");        		
        bool validInput = false;
        int number;
        while (!validInput) {            
            int result = scanf("%d", &number);
            if (result == 1&&number>0&&number<10) {            
                validInput = true;
                getchar();
                printf("输入成功\n");
            }
            else {
                printf("输入的不是有效的整数，请重新输入。\n");
                // 清空输入缓冲区
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
            }
        }
        switch (number) {
            case 1: {
                system("cls");   // 清屏
                if (sign==0)
                {
                    s = initLStack(); 
                    sign = 1;
                    printf("栈初始化成功\n");
                }
                else {
                    printf("栈已经初始化\n");
                }
                system("pause");
                break;
            }
            case 2: {
            // 实现判断栈是否为空的功能
                system("cls");
                int sign = isEmptyLStack(s);
                if (sign==ERROR)
                {
                    printf("栈不存在\n");
                }
                system("pause");
                 break;
            }
            case 3: {
                // 得到栈顶元素
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
                    printf("栈长度为%d\n", length);
                }
                system("pause");
                break;
            }
            case 7: {
                system("cls");
                bool validInput = false;
                int number;
                while (!validInput) {
	                printf("请输入入栈的结点对应的data值(需要是整数): ");
	                int result = scanf("%d", &number);
	                if (result == 1) {
		                validInput = true;
                        getchar();
		                printf("输入成功\n");
	                }
           	        else {
		                printf("输入的不是有效的整数，请重新输入。\n");
		                // 清空输入缓冲区
		                int c;
		                while ((c = getchar()) != '\n' && c != EOF);
	                }
                }
                int sign = pushLStack(s, number);
                if (sign == ERROR)
                {
                    printf("栈不存在,无法入栈\n");
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
                    printf("已出栈,其值为%d\n",data);
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
