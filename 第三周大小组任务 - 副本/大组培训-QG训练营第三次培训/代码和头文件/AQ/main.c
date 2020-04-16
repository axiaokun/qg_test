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
        printf("操作结果：");
        if(i<1||i>8)
        {
            printf("输入的数据不合法，请重新输入！\n");
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
                    printf("入队成功!\n");
                else 
                    printf("入列失败！\n");
            }
            else 
                printf("入列失败!\n");
            break;
        case 4:
            if(GetHeadAQueue(&Q, (void*)&e))
                APrint(&e);
            else 
                printf("查看失败！\n");
            break;
        case 5:
        {
            void (*foo)(void *q);
            foo = APrint;
            if(TraverseAQueue(&Q, foo))
                printf("遍历成功！\n");
            else 
                printf("遍历失败！\n");
            break;
        }
        case 6:
            ClearAQueue(&Q);
            break;
        case 7:
            if(DeAQueue(&Q))
                printf("出队成功！\n");
            else 
                printf("出队失败！\n");
            break;
        case 8:
            printf("程序关闭！\n");
            exit(0);
            break;
        }
    }
    return 0;
} 


