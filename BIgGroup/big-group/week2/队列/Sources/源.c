#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include "LQueue.h"
#include <stdbool.h>
int sign = 0;
void menu()
{
    printf("************************\n");
    printf("**  1.初始化队列      **\n");
    printf("**  2.判断队列是否为空**\n");
    printf("**  3.得到队头元素    **\n");
    printf("**  4.清空队列        **\n");
    printf("**  5.销毁队列        **\n");
    printf("**  6.检测队长度      **\n");
    printf("**  7.入队            **\n");
    printf("**  8.出队            **\n");
    printf("**  9.遍历队列        **\n");
    printf("**  10.退出程序       **\n");
    printf("************************\n");
}
int Specification_input(int limit) {
    bool validInput = false;
    int number;
    while (!validInput) {
        int result = scanf("%d", &number);
        if (result == 1 && number > 0 && number < limit) {
            validInput = true;
            getchar();
            printf("输入成功\n");
            return number;
        }
        else {
            printf("输入的不是有效的整数，请重新输入。\n");
            // 清空输入缓冲区
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
    }
}
Status GetHeadLQueue(LQueue* Q, void** e,DataType* type) {
    if (IsEmptyLQueue(Q) == FALSE) {
        return FALSE;
    }
    *e = Q->front->data;
    *type = Q->front->type;
    return TRUE;
}
int LengthLQueue(LQueue* Q) {
    return Q->length;
}
Status IsEmptyLQueue( LQueue* Q) {
    if (Q==NULL)
    {
        printf("队列不存在\n");
        return FALSE;
    }
    if (Q->length==0)
    {
        printf("队列为空\n");
        return FALSE;
    }
    else {
        printf("队列不为空\n");
        return TRUE;
    }
}
void LPrint(void* q,DataType type) {
    if (type == INT) {
        printf("%d\n", *((int*)q));
    }
    else if (type==FLOAT)
    {
        printf("%f\n", *((float*)q));
    }
    else if (type==CHAR) {
        printf("%c\n", *((char*)q));
    }
}
Status TraverseLQueue( LQueue* Q) {
    if (IsEmptyLQueue(Q) == FALSE) {
        return FALSE;
    }
    printf("遍历结果如下\n");
    Node* node = Q->front;
    while (node!=NULL)
    {       
        LPrint(node->data,node->type);
        node = node->next;
    }
    return TRUE;
}
LQueue* InitLQueue(LQueue* Q) {
    Q = (LQueue*)malloc(sizeof(LQueue));
    Q->front = NULL;
    Q->rear = NULL;
    Q->length = 0;
    sign = 1;
    return Q;
}
void ClearLQueue(LQueue* Q) {
    if (IsEmptyLQueue(Q) == FALSE) {
        return;
    }
    if (Q->length==1)
    {
        Node* node = Q->front;
        free(node);
        Q->front = NULL;
        Q->rear = NULL;
        Q->length = 0;
        printf("队列已清空\n");
        return;
    }
    else
    {
        while (Q->front->next != NULL)
        {
            Node* node = Q->front;
            Q->front = Q->front->next;
            free(node);
        }
        free(Q->front);
        Q->front = NULL;
        Q->rear = NULL;
        Q->length = 0;
        printf("队列已清空\n");
        return;
    }
}
void DestoryLQueue(LQueue** Q) {
    ClearLQueue(*Q);
    free(*Q);
    *Q = NULL;
    printf("队列已摧毁\n");
    sign = 0;
}
Status EnLQueue(LQueue* Q, void* data,DataType type) {  
        if (Q == NULL) {
            printf("队列不存在,入队失败\n");
            return FALSE;
        }
        Node* node = (Node*)malloc(sizeof(Node));
        if (node == NULL) {
            printf("内存分配失败\n");
            return FALSE;
        }      
        if (node->data == NULL) {
            free(node);
            printf("内存分配失败\n");
            return FALSE;
        }
        // 根据数据类型进行内存拷贝
        switch (type) {
        case INT:
            node->data =malloc(sizeof(int));
            *((int*)node->data) = *((int*)data);
            break;
        case FLOAT:
            node->data = malloc(sizeof(float));
            *((float*)node->data) = *((float*)data);
            break;
        case CHAR:
            node->data = malloc(sizeof(char));
            *((char*)node->data) = *((char*)data);
            break;
        default:
            free(node->data);
            free(node);
            printf("不支持的数据类型\n");
            return FALSE;
        }
        node->type = type;
        node->next = NULL;
        if (Q->length != 0) {
            Q->rear->next = node;
            Q->rear = node;
        }
        else {
            Q->front = node;
            Q->rear = node;
        }
        Q->length++;
        printf("入队成功\n");
        return TRUE;
    }

Status DeLQueue(LQueue* Q) {
    if (IsEmptyLQueue(Q) == FALSE) {
        return FALSE;
    }
    Node* node = (Node*)malloc(sizeof(Node));
    if (Q->length!=1 ) {
        node = Q->front;
        Q->front = Q->front->next;
        free(node);
        printf("出队成功\n");
        Q->length--;
        return TRUE;
    }
    else
    {
        free(Q->front);
        Q->front = NULL;
        Q->rear = NULL;
        printf("出队成功\n");
        Q->length--;
        return TRUE;
    }
}
void menu_control(LQueue* Q) {
    while (1) {
        system("cls");
        menu();
        printf("请输入你要选择的功能的编号:");
        int number = Specification_input(11);
        switch (number) {
        case 1: {
            system("cls");   // 清屏
            if (sign==0)
            {
                Q = InitLQueue(Q);
                printf("队列初始化成功\n");
            }
            else
            {
                printf("队列已初始化\n");
            }
            system("pause");
            break;
        }
        case 2: {           
            system("cls");
            IsEmptyLQueue(Q);
            system("pause");
            break;
        }
        case 3: {    
            system("cls");
            void* e=NULL;
            DataType type;
            Status temp=GetHeadLQueue(Q,&e,&type);
            if (temp==TRUE)
            {
                printf("队头元素为:");
                LPrint(e, type);               
            }
            system("pause");
            break;
        }
        case 4: {
            system("cls");
            ClearLQueue(Q);
            system("pause");
            break;
        }
        case 5: {
            system("cls");
            DestoryLQueue(&Q);
            system("pause");
            break;
        }
        case 6: {        
            system("cls");
            if (Q==NULL)
            {
                printf("队列不存在\n");
            }
            else
            {
               int length=LengthLQueue(Q);
               printf("队列长度为%d\n",length);
            }
            system("pause");
            break;
        }
        case 7: {
            system("cls");
            printf("请输入要入队的元素的类型(1代表INT,2代表FLOAT,3代表CHAR):");
            int a = Specification_input(4);         
            if (a == 1) {
                int* e=NULL;
                int temp;
                printf("请输入要入队的元素的值:");
                bool validInput = false;               
                while (!validInput) {
                    int result = scanf("%d", &temp);
                    if (result == 1 ) {
                        validInput = true;
                        getchar();
                        printf("输入成功\n");
                    }
                    else {
                        printf("输入的不是有效的值，请重新输入。\n");
                        // 清空输入缓冲区
                        int c;
                        while ((c = getchar()) != '\n' && c != EOF);
                    }
                }
                e = &temp;
                EnLQueue(Q, e, INT);
            }
            else if (a == 2)
            {
                float* e=NULL;
                float temp;
                printf("请输入要入队的元素的值:");
                bool validInput = false;
                while (!validInput) {
                    int result = scanf("%f", &temp);
                    if (result == 1) {
                        validInput = true;
                        getchar();
                        printf("输入成功\n");
                    }
                    else {
                        printf("输入的不是有效的值，请重新输入。\n");
                        // 清空输入缓冲区
                        int c;
                        while ((c = getchar()) != '\n' && c != EOF);
                    }
                }
                e = &temp;
                EnLQueue(Q, e, FLOAT);
            }else
            {
                char* e=NULL;
                char temp;
                printf("请输入要入队的元素的值:");
                bool validInput = false;
                while (!validInput) {
                    int result = scanf("%c", &temp);
                    if (result == 1) {
                        validInput = true;
                        getchar();
                        printf("输入成功\n");
                    }
                    else {
                        printf("输入的不是有效的值，请重新输入。\n");
                        // 清空输入缓冲区
                        int c;
                        while ((c = getchar()) != '\n' && c != EOF);
                    }
                }
                e = &temp;
                EnLQueue(Q, e, CHAR);
            } 
            system("pause");
            break;
        }
        case 8: {
            system("cls");
            DeLQueue(Q);
            system("pause");
            break;
        }
        case 9: {
            system("cls");
            TraverseLQueue(Q);
            system("pause");
            break;
        }
        case 10: {
            system("cls");
            exit(0);
        }
        }
    }
}

int main() {
    LQueue* Q = NULL;
    menu_control(Q);
}