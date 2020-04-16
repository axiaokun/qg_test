#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include"../LQueue/LQueue.h"

// ��ʼ������
void InitLQueue(LQueue *Q)
{
    if(Q->front != NULL)
    {
        printf("�ö����Ѿ���ʼ����\n");
        return;
    }
    else 
    {
        Q->front = Q->rear = (Node *)malloc(sizeof(Node));
        Q->rear->data = (void*)malloc(MAXSTRING);
        Q->rear->next = NULL;
        Q->length = 0;
        printf("�������гɹ���\n");
    }
}

// ���ٶ���
void DestoryLQueue(LQueue *Q)
{
    Node *q;
    if(Q->front == NULL)
    {
        printf("�ö��л�δ��ʼ����\n");
        return;
    }
    else 
    {
        while(Q->front != NULL)  // �Ӷ�ͷ��ʼ�ͷ��ڴ�
        {
            q = Q->front;
            Q->front = q->next;
            free(q->data);
            free(q);
        }
        Q->rear = Q->front = NULL;
    }
    printf("���ٳɹ���\n");
}

// �ж��Ƿ�Ϊ��
Status IsEmptyLQueue(const LQueue *Q)
{
    if(Q->length == 0)
        return TRUE;
    else 
        return FALSE;
}

// ��ȡ��ͷԪ��
Status GetHeadLQueue(LQueue *Q, void *e)
{
    if(Q->front == NULL)
    {
        printf("�ö��л�δ��ʼ��!\n");
        return FALSE;
    }
    if(IsEmptyLQueue(Q))
    {
        printf("����Ϊ�գ�\n");
        return FALSE;
    }
    memcpy(e, Q->front->next, sizeof(Node));
    return TRUE;
}

// ��ȡ���г���
int LengthLQueue(LQueue *Q)
{
    return Q->length;
}

// ����������Ԫ��
Status EnLQueue(LQueue *Q)
{
    if(Q->front == NULL)
    {
        printf("���л�δ��ʼ����\n");
        return FALSE;
    }
    Node * new = (Node *)malloc(sizeof(Node));
    printf("����Ҫ����������ͣ�\n\
                1. ����    2. �ַ�   3. �������������ȣ�  4. ��������˫���ȣ�\n");
    new->type = pchuo();
    while(new->type<1 || new->type>4)
    {
        printf("������Ϸ����ݣ�\n");
        new->type = pchuo();
    }
    printf("������������ݣ�\n");
    switch (new->type)
    {
    case 1:
    {
        new->data = (int*)malloc(sizeof(int));
        int num = pchuo();
        *(int *)new->data = num;
        break;
    }
    case 2:
    {
        getchar();
        new->data = (char *)malloc(sizeof(char));
        char data;
        pho(&data, new->type);
        *(char *)new->data = data;
        break;
    }
    case 3:
    {
        getchar();
        new->data = (float*)malloc(sizeof(float));
        float data;
        pho(&data, new->type);
        *(float *)new->data = data;
        break;
    }
    case 4:
    {
        getchar();
        new->data = (double*)malloc(sizeof(double));
        double data;
        pho(&data, new->type);
        *(double *)new->data = data;
        break;
    }
    }
    Q->rear->next = new;
    Q->rear = new;
    Q->length++;
    Q->rear->next = NULL;
    return TRUE;
}

// ��������
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
{
    if(Q->front == NULL)
    {
        printf("����δ��ʼ����\n");
        return FALSE;
    }
    if(IsEmptyLQueue(Q))
    {
        printf("����Ϊ�գ�\n");
        return FALSE;
    }
    Node* temp = Q->front->next;
    while(temp)
    {
        foo(temp);
        temp = temp->next;
    }
    return TRUE;
}

// ��ӡ����Ԫ��
void LPrint(void *q)
{
    Node* temp = (Node *)q;
    switch (temp->type)
    {
    case 1:
        printf("-->%d", *(int *)temp->data);
        break;
    case 2:
        printf("-->%c", *(char *)temp->data);
        break;
    case 3:
        printf("-->%f", *(float *)temp->data);
        break;
    case 4:
        printf("-->%.10lf", *(double *)temp->data);
        break;
    }
}

// ��ն���
Status DeLQueue(LQueue *Q)
{
    if(Q->front == NULL)
    {
        printf("�ö���δ��ʼ����\n");
        return FALSE;
    }
    if(IsEmptyLQueue(Q))
    {
        printf("�ö���Ϊ�գ�\n");
        return FALSE;
    }
    Node * temp = Q->front;
    Q->front = temp->next;
    free(temp->data);
    free(temp);
    Q->length--;
}

// �淶����
int pchuo(void)
{
    int len, num = 0, arg = 1;
    char word[MAXSTRING];
    int m, j= 1, k;
    while(j)
    {
        scanf("%s", word);
        len = strlen(word);
        for(m = 0;m<len;m++)
        {
            if(word[m]<'0' || word[m]>'9')
            {
                printf("������Ϸ����ݣ�\n");
                break;
            }
            else 
            {
                if(m == len-1)
                    j = 0;
            }
        }
    }
    j = len-1;
    for(m=0;m<len;m++)
    {
        for(k=0;k<j;k++)
            arg *= 10;
        num += (word[m]-'0')*arg;
        arg = 1;
        j--;
    }
    return num;
}

// �淶�ַ�  ������
void pho(void *e, int type)
{
    int len, pop_num = 0, real_num = 0, pop_location, isok = 1;
    float arg = 1;
    double num = 0;
    char word[MAXSTRING];
    int m, j= 1, k;
    while(j)
    {
        scanf("%s", word);
        len = strlen(word);
        if(type == 2)
        {
            if(len != 1)
            {
                printf("�������ݲ��Ϸ������������룡\n");
                continue;
            }
            else 
            {
                if(word[0]>'a'&&word[0]<'z' || word[0]>'A'&&word[0]<'Z')
                {
                    *(char *)e = word[0];
                    return;
                }
                else 
                {
                    printf("�������ݲ��Ϸ������������룡\n");
                    continue;
                }
            }
        }
        if(type == 3 || type == 4)
        {
            isok = 1;
            for(m = 0;m<len;m++)
            {
                if(word[m]>='0' && word[m]<='9' || word[m] == '.')
                {
                    if(word[m] == '.' && m == 0)
                    {
                        printf("������Ϸ����ݣ�\n");
                        isok = 0;
                        break;
                    }
                    if(word[m] == '0' && m == 0)
                    {
                        if(word[m+1] != '.')
                        {
                            printf("������Ϸ����ݣ�\n");
                            isok = 0;
                            break;
                        }
                    }
                    if(word[m] == '.')
                    {
                        pop_num++;
                        if(pop_num == 2)
                        {
                            printf("������Ϸ����ݣ�");
                            isok = 0;
                            break;
                        }
                        pop_location = m;
                    }
                    else
                    {
                        real_num++;
                        if(real_num == 6 && type == 3)
                        {
                            printf("С����������Ч�����ܺͲ�����6λ�����������룡\n");
                            isok = 0;
                            break;
                        }
                        if(real_num == 16 && type == 4)
                        {
                            printf("С����������Ч�����ܺͲ�����16λ�����������룡\n");
                            isok = 0;
                            break;
                        }
                    }
                }
                else 
                {
                    printf("������Ϸ����ݣ�\n");
                    isok = 0;
                    break;
                }
            }
            if(isok)
            {
                if(pop_num == 1)
                {
                    for(m=0;m<pop_location;m++)
                    {
                        for(k=m;k<pop_location-1;k++)
                            arg *= 10.0;
                        num += (word[m]-'0')*arg;
                        arg = 1;
                    }
                    for(m = len-1;m>pop_location;m--)
                    {
                        for(k=m;k>pop_location;k--)
                            arg /= 10.0;
                        num += (word[m]-'0')*arg;
                        arg = 1;
                    }
                }
                else 
                {
                    j = len-1;
                    for(m=0;m<len;m++)
                    {
                        for(k=0;k<j;k++)
                            arg *= 10;
                        num += (word[m]-'0')*arg;
                        arg = 1;
                        j--;
                    }
                }
                if(type == 3)
                {
                    *(float *)e = (float)num;
                }
                else 
                    *(double*)e = num;
                j = 0;
            }
        }
    }
}

void ClearLQueue(LQueue *Q)
{
    if(Q->front == NULL)
    {
        printf("�ö���δ��ʼ��!\n");
        return;
    }
    if(IsEmptyLQueue(Q))
    {
        printf("�ö����Ѿ�Ϊ�գ�\n");
        return;
    }
    Node *temp = Q->front->next;
    Node *P;
    while(temp)
    {
        P = temp;
        temp = P->next;
        free(P->data);
        free(P);
    }
    Q->rear = Q->front;
    Q->front->next = NULL;
    Q->length = 0;
}

