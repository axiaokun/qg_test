#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "../AQueue/AQueue.h"


int main(void)
{
    Mydata e;
    AQueue Q;
    Q.data[0] = NULL;
    int i;
    show_ui();
    while(1)
    {
        i = pchuo();
        system("cls");
        show_ui();
        printf("���������");
        if(i<1||i>8)
        {
            printf("��������ݲ��Ϸ������������룡\n");
            continue;
        }
        switch (i)
        {
        case 1:
            InitAQueue(&Q);
            break;
        case 2:
            DestoryAQueue(&Q);
            break;
        case 3:
            if(inputdata(&e, &Q))
            {
                if (EnAQueue(&Q, (void *)&e))
                    printf("��ӳɹ�!\n");
                else 
                    printf("����ʧ�ܣ�\n");
            }
            else 
                printf("����ʧ��!\n");
            break;
        case 4:
            if(GetHeadAQueue(&Q, (void*)&e))
                APrint(&e);
            else 
                printf("�鿴ʧ�ܣ�\n");
            break;
        case 5:
        {
            void (*foo)(void *q);
            foo = APrint;
            if(TraverseAQueue(&Q, foo))
                printf("�����ɹ���\n");
            else 
                printf("����ʧ�ܣ�\n");
            break;
        }
        case 6:
            ClearAQueue(&Q);
            break;
        case 7:
            if(DeAQueue(&Q))
                printf("���ӳɹ���\n");
            else 
                printf("����ʧ�ܣ�\n");
            break;
        case 8:
            printf("����رգ�\n");
            exit(0);
            break;
        }
    }
    return 0;
} 


