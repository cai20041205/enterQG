#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include "LQueue.h"
#include <stdbool.h>
int sign = 0;
void menu()
{
    printf("************************\n");
    printf("**  1.��ʼ������      **\n");
    printf("**  2.�ж϶����Ƿ�Ϊ��**\n");
    printf("**  3.�õ���ͷԪ��    **\n");
    printf("**  4.��ն���        **\n");
    printf("**  5.���ٶ���        **\n");
    printf("**  6.���ӳ���      **\n");
    printf("**  7.���            **\n");
    printf("**  8.����            **\n");
    printf("**  9.��������        **\n");
    printf("**  10.�˳�����       **\n");
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
            printf("����ɹ�\n");
            return number;
        }
        else {
            printf("����Ĳ�����Ч�����������������롣\n");
            // ������뻺����
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
        printf("���в�����\n");
        return FALSE;
    }
    if (Q->length==0)
    {
        printf("����Ϊ��\n");
        return FALSE;
    }
    else {
        printf("���в�Ϊ��\n");
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
    printf("�����������\n");
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
        printf("���������\n");
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
        printf("���������\n");
        return;
    }
}
void DestoryLQueue(LQueue** Q) {
    ClearLQueue(*Q);
    free(*Q);
    *Q = NULL;
    printf("�����Ѵݻ�\n");
    sign = 0;
}
Status EnLQueue(LQueue* Q, void* data,DataType type) {  
        if (Q == NULL) {
            printf("���в�����,���ʧ��\n");
            return FALSE;
        }
        Node* node = (Node*)malloc(sizeof(Node));
        if (node == NULL) {
            printf("�ڴ����ʧ��\n");
            return FALSE;
        }      
        if (node->data == NULL) {
            free(node);
            printf("�ڴ����ʧ��\n");
            return FALSE;
        }
        // �����������ͽ����ڴ濽��
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
            printf("��֧�ֵ���������\n");
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
        printf("��ӳɹ�\n");
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
        printf("���ӳɹ�\n");
        Q->length--;
        return TRUE;
    }
    else
    {
        free(Q->front);
        Q->front = NULL;
        Q->rear = NULL;
        printf("���ӳɹ�\n");
        Q->length--;
        return TRUE;
    }
}
void menu_control(LQueue* Q) {
    while (1) {
        system("cls");
        menu();
        printf("��������Ҫѡ��Ĺ��ܵı��:");
        int number = Specification_input(11);
        switch (number) {
        case 1: {
            system("cls");   // ����
            if (sign==0)
            {
                Q = InitLQueue(Q);
                printf("���г�ʼ���ɹ�\n");
            }
            else
            {
                printf("�����ѳ�ʼ��\n");
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
                printf("��ͷԪ��Ϊ:");
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
                printf("���в�����\n");
            }
            else
            {
               int length=LengthLQueue(Q);
               printf("���г���Ϊ%d\n",length);
            }
            system("pause");
            break;
        }
        case 7: {
            system("cls");
            printf("������Ҫ��ӵ�Ԫ�ص�����(1����INT,2����FLOAT,3����CHAR):");
            int a = Specification_input(4);         
            if (a == 1) {
                int* e=NULL;
                int temp;
                printf("������Ҫ��ӵ�Ԫ�ص�ֵ:");
                bool validInput = false;               
                while (!validInput) {
                    int result = scanf("%d", &temp);
                    if (result == 1 ) {
                        validInput = true;
                        getchar();
                        printf("����ɹ�\n");
                    }
                    else {
                        printf("����Ĳ�����Ч��ֵ�����������롣\n");
                        // ������뻺����
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
                printf("������Ҫ��ӵ�Ԫ�ص�ֵ:");
                bool validInput = false;
                while (!validInput) {
                    int result = scanf("%f", &temp);
                    if (result == 1) {
                        validInput = true;
                        getchar();
                        printf("����ɹ�\n");
                    }
                    else {
                        printf("����Ĳ�����Ч��ֵ�����������롣\n");
                        // ������뻺����
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
                printf("������Ҫ��ӵ�Ԫ�ص�ֵ:");
                bool validInput = false;
                while (!validInput) {
                    int result = scanf("%c", &temp);
                    if (result == 1) {
                        validInput = true;
                        getchar();
                        printf("����ɹ�\n");
                    }
                    else {
                        printf("����Ĳ�����Ч��ֵ�����������롣\n");
                        // ������뻺����
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