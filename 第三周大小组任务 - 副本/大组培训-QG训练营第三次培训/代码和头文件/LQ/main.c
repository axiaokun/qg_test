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
    Q.front = Q.rear = NULL;  // 先将指针指向null
    while(1)
    {
        printf("\n请输入您的选择\n\
            1:创建队列    2:销毁队列    3:入队   4:查看队头元素   \n\
            5.遍历队列  6.清空队列   7.出队成功\n\
            8.结束程序 \n");
        i = pchuo();
        system("cls");
        printf("操作结果：");
        if(i<1||i>8)
        {
            printf("输入的数据不合法，请重新输入！\n");
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
                printf("入队成功！\n");
            else 
                printf("入队失败！\n");
            break;
        case 4:
            if(GetHeadLQueue(&Q, &P))
            {
                LPrint(&P);
                printf("查看成功！\n");
            }
            else 
                printf("查看失败！\n");     
            break;    
        case 5:
        {
            void (*foo)(void *q);
            foo = LPrint;
            if(TraverseLQueue(&Q, foo))
                printf("遍历成功！\n");
            else 
                printf("遍历失败！\n");
            break;
        } 
        case 6:
            ClearLQueue(&Q);
            break;
        case 7:
            if(DeLQueue(&Q))
                printf("出队成功！\n");
            else 
                printf("出队失败！\n");
            break;
        case 8:
            printf("程序结束！\n");
            exit(0);      
        }
    }
    return 0;
}


