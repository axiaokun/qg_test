#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include"../LQueue/LQueue.h"

int main(void)
{
    int i;
    Node P;
    LQueue Q;
    Q.front = Q.rear = NULL;  // �Ƚ�ָ��ָ��null
    while(1)
    {
        printf("\n����������ѡ��\n\
            1:��������    2:���ٶ���    3:���   4:�鿴��ͷԪ��   \n\
            5.��������  6.��ն���   7.���ӳɹ�\n\
            8.�������� \n");
        i = pchuo();
        system("cls");
        printf("���������");
        if(i<1||i>8)
        {
            printf("��������ݲ��Ϸ������������룡\n");
            continue;
        }
        switch (i)
        {
        case 1:
            InitLQueue(&Q);
            break;
        case 2:
            DestoryLQueue(&Q);
            break;
        case 3:
            if(EnLQueue(&Q))
                printf("��ӳɹ���\n");
            else 
                printf("���ʧ�ܣ�\n");
            break;
        case 4:
            if(GetHeadLQueue(&Q, &P))
            {
                LPrint(&P);
                printf("�鿴�ɹ���\n");
            }
            else 
                printf("�鿴ʧ�ܣ�\n");     
            break;    
        case 5:
        {
            void (*foo)(void *q);
            foo = LPrint;
            if(TraverseLQueue(&Q, foo))
                printf("�����ɹ���\n");
            else 
                printf("����ʧ�ܣ�\n");
            break;
        } 
        case 6:
            ClearLQueue(&Q);
            break;
        case 7:
            if(DeLQueue(&Q))
                printf("���ӳɹ���\n");
            else 
                printf("����ʧ�ܣ�\n");
            break;
        case 8:
            printf("���������\n");
            exit(0);      
        }
    }
    return 0;
}


