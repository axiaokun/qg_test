#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include "../AQueue/AQueue.h"

// ��ʼ������
void InitAQueue(AQueue *Q)
{
    if(Q->data[0] != NULL)
    {
        printf("�����Ѿ���ʼ����");
        return;
    }
    else 
    {
        int i;
        Q->length = MAXQUEUE;  // ���г��ȣ�ע������ʹ��������д洢�Ķ��г����Ѿ��̶�������ĳ��Ⱦ������ĳ���
        for(i = 0;i<MAXQUEUE;i++)
            Q->data[i] = malloc(sizeof(Mydata));// ָ�������ÿһ��Ԫ��ָ�򿪱ٺýڵ��С�ڴ������
        Q->front = Q->rear = 0;
        printf("�ɹ��������У�\n");
    }
}

// ���ٶ���
void DestoryAQueue(AQueue *Q)
{
    if(isint(Q))
    {
        int i;
        for (i=0;i<MAXQUEUE;i++)
            free(Q->data[i]);// �ͷ�ָ������ָ��������ڴ�
        Q->data[0] = NULL;
        printf("���ٳɹ���\n");
        return;
    }
    printf("����ʧ��!\n");
}

// ���ض����Ƿ�����״̬
Status IsFullAQueue(const AQueue *Q)
{
    if (LengthAQueue((AQueue *)Q) == Q->length-1)// ��������Ѵ���Ԫ�ص�λ�ĳ��ȵ�����󳤶ȼ�һ����ô��������
        return TRUE;// ����ʵ��ѭ�����л�����һ�����е�λ����Զ��н��в���
    else 
        return FALSE;
}

// �ж��Ƿ�Ϊ��
Status IsEmptyAQueue(const AQueue *Q)
{
    if (LengthAQueue((AQueue *)Q) == 0) // ��������Ѵ���Ԫ�ص�λ�ĳ���Ϊ0,��ô����Ϊ��
        return TRUE;
    else 
        return FALSE;
}

// ��ö�ͷԪ��
Status GetHeadAQueue(AQueue *Q, void *e)
{
    if (isint(Q))
    {
        if (IsEmptyAQueue(Q))
        {
            printf("����Ϊ�գ�\n");
            return FALSE;
        }
        else 
        {
            memcpy(e, Q->data[Q->front], sizeof(Mydata));
            return TRUE;
        }
    }
    else
        return FALSE;
}

// ��������Ѵ���Ԫ�ص�λ�ĳ���
int LengthAQueue(AQueue *Q)
{
    return (Q->rear - Q->front + Q->length)%Q->length;
}

// ��Ӳ���
Status EnAQueue(AQueue *Q, void *data)
{
    memcpy(Q->data[Q->rear], data, sizeof(Mydata));
    Q->rear = (Q->rear + 1)%Q->length;
    return TRUE;
}

Status isint(const AQueue *Q)
{
    if (Q->data[0] == NULL)
    {
        printf("���в����ڣ����ȳ�ʼ������\n");
        return FALSE;
    }
    return TRUE;
}

// ��������
Status inputdata(Mydata *e, AQueue *Q)
{
    if (isint(Q))
    {
        if (IsFullAQueue((const AQueue*)Q))
        {
            printf("�����Ѿ����ˣ�����������Ԫ���ˣ�");
            return FALSE;
        }
        else
        {
            printf("����Ҫ����������ͣ�\n\
                    1. ����    2. �ַ�   3. �������������ȣ�  4. ��������˫���ȣ�\n");
            int i;
            while(1)
            {
                i = pchuo();
                if(i<1 || i>4)
                {
                    printf("������Ϸ����ݣ�\n");
                    continue;
                }
                break;
            }
            e->type = i;
            printf("������������ݣ�");
            switch (e->type)  // ������Ҫ����������������� 
            {
            case Int:
                e->INT = pchuo();
                break;
            case Char:
            {
                getchar();
                char* data;
                pho(data, e->type);
                e->CHAR = *data;
                break;
            }
            case Float:
            {
                getchar();
                float data;
                pho((void*)&data, e->type);
                e->FLOAT = data;
                break;
            }
            case Double:
            {
                getchar();
                double data;
                pho((void*)&data, e->type);
                e->DOULBLE = data;
                break;
            }
            default:
                break;
            }
            return TRUE;
        }
    }
    return FALSE;
}

// ���ݽڵ������ݵ����ʹ�ӡ����
void APrint(void *q)
{
    Mydata *Q = (Mydata *)q;
    if(Q->type == Int)
        printf("-->%d", Q->INT);
    if(Q->type == Char)
        printf("-->%c", Q->CHAR);
    if(Q->type == Float)
        printf("-->%.6f", Q->FLOAT);
    if(Q->type == Double)
        printf("-->%.10lf", Q->DOULBLE);
}

// ��ն���
void ClearAQueue(AQueue *Q)
{
    if(isint(Q))
    {
        if(IsEmptyAQueue(Q))
            printf("�ö����Ѿ�Ϊ�գ�\n");
        else 
            Q->front = Q->rear = 0;
    }
}

// ��������
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
{
    if(isint(Q))
    {
        if(IsEmptyAQueue(Q))
        {
            printf("�ö���Ϊ�գ��޷�����\n");
            return FALSE;
        }
        else 
        {
            int i = 0;
            while(i<LengthAQueue((AQueue*)Q))
            {
                foo(Q->data[(Q->front+i)%(Q->length)]);  // ����Ӧ�ڵ㴫������ݲ����ĺ�����
                i++;
            }
            return TRUE;
        }
    }
    return FALSE;
}

// ����
Status DeAQueue(AQueue *Q)
{
    if(isint(Q))
    {
        if(IsEmptyAQueue(Q))
        {
            printf("����Ϊ�գ��޷����ӣ�\n");
            return FALSE;
        }
        else 
        {
            Q->front = (Q->front+1)%Q->length;  // ʵ���Ͼ��ǰѶ�ͷָ�������ƶ�
            return TRUE;
        }
    }
    else 
        return FALSE;
}

// �淶����Ϊ����
int pchuo(void)
{
    int len, num = 0, arg = 1;
    char word[MAXSTRING];
    int m, j= 1, k;
    while(j)
    {
        scanf("%s", word);
        len = strlen(word);  //�����ַ���
        for(m = 0;m<len;m++)
        {
            if(word[m]<'0' || word[m]>'9')
            {
                printf("������Ϸ����ݣ�\n");  //Ҫ�ǳ��ֲ�����0��9���ַ�ֹͣforѭ����������
                break;
            }
            else 
            {
                if(m == len-1)
                    j = 0;  // ��������û�м�鵽�����ϵ��ַ��Ϳ�����ֹwhileѭ��
            }
        }
    }
    j = len-1;
    for(m=0;m<len;m++)  // ���ַ���ת��Ϊ����
    {
        for(k=0;k<j;k++)
            arg *= 10;  
        num += (word[m]-'0')*arg;
        arg = 1;
        j--;
    }
    return num;
}

// �������ݵ�e�У��ж��ַ�  ������
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
        if(type == 2)  // ���ѡ�������Ϊ�ַ���ִ����һ��if������������
        {
            if(len != 1)  // �������ַ����Գ���Ϊ1
            {
                printf("�������ݲ��Ϸ������������룡\n");
                continue;
            }
            else 
            {  // ����ֻ�涨����Ӣ����ĸ�ַ�
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
        if(type == 3 || type == 4)  // ��һ���������־��ȸ�����
        {
            isok = 1;  // isok�ǽ������Ƿ�Ҫ���ַ���ת��Ϊ������������
            for(m = 0;m<len;m++)
            {
                if(word[m]>='0' && word[m]<='9' || word[m] == '.')
                {
                    if(word[m] == '.' && m == 0)  // ��ͷΪ. ������һ������������ʽ
                    {
                        printf("������Ϸ����ݣ�\n");
                        isok = 0;
                        break;
                    }
                    if(word[m] == '0' && m == 0)  // ��ͷΪ0�����治��С����Ҳһ��������
                    {
                        if(word[m+1] != '.')
                        {
                            printf("������Ϸ����ݣ�\n");
                            isok = 0;
                            break;
                        }
                    }
                    if(word[m] == '.')  // С�������������һ��Ҳ������
                    {
                        pop_num++;
                        if(pop_num == 2)
                        {
                            printf("������Ϸ����ݣ�");
                            isok = 0;
                            break;
                        }
                        pop_location = m;  // ����С�����λ�ã�����Ҫ
                    }
                    else
                    {
                        real_num++;
                        if(real_num == 6 && type == 3)  // ���ݾ��Ȳ�ͬ�ж��Ƿ����
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
            {  // ���������ľͿ��Խ��ַ���ת��ɸ�������,ע���������õ����洢�浽��С�����λ��
                for(m=0;m<pop_location;m++)
                {
                    for(k=m;k<pop_location-1;k++)
                        arg *= 10.0;  // �����۳�10
                    num += (word[m]-'0')*arg;  // С����ǰ�����ֳ�����������۳�10������
                    arg = 1;
                }
                for(m = len-1;m>pop_location;m--)
                {
                    for(k=m;k>pop_location;k--)
                        arg /= 10.0;  // �����۳�
                    num += (word[m]-'0')*arg;  // С�����������ֳ�����������۳�������
                    arg = 1;
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

void show_ui(void)
{
	printf("����������ѡ��\n\
            1:��������    2:���ٶ���    3:���   4:�鿴��ͷԪ��   \n\
            5.��������  6.��ն���   7.���ӳɹ� \n\
            8. ��������\n");
}


