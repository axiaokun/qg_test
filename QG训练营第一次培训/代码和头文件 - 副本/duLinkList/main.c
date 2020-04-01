#include "../head/duLinkedList.h"
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>




int main(void)
{
    DuLinkedList phead, pnew, ptail;
    phead = pnew = NULL;
    int choice_num;
    do 
    {
        printf("\n\n\n\n  ******************************************************\n");
        printf("  *  1.创建空链表       2.遍历链表      3.释放链表       *\n");
        printf("  *  4.头部插入元素             5.尾部插入元素         *\n");
        printf("  *                              0.结束(注意要先释放链表)*\n");
        printf("  ******************************************************\n");
        printf("请选择操作编号：");
        choice_num = judge_int();
        system("cls");
        switch(choice_num)
        {
        case 1:
            if (InitList_DuL(&phead))
                printf("创建成功！\n");
            else 
                printf("创建失败！\n");
            break;
        case 2:
            if(phead == NULL || phead->next == NULL)
                printf("链表不存在或者只存在一个空的头结点\n");
            else 
                TraverseList_DuL(phead, print);
            break;
        case 3:
            if(phead == NULL)
                printf("链表不存在！\n");
            else 
                DestroyList_DuL(&phead);
            break;
        case 4:
            if(InitList_DuL(&pnew))
                put_in(pnew);
            if(InsertAfterList_DuL(phead, pnew))
                printf("成功插入节点！\n");
            else 
            {
                printf("操作失败！\n");
                free(pnew);
                pnew = NULL;
            }
            break;
        case 5:
            if(InitList_DuL(&pnew))
                put_in(pnew);
            if(phead == NULL)
            {
                printf("先创建链表！\n");
                free(pnew);
                break;
            }
            ptail = phead;
            while(ptail->next != NULL)
                ptail = ptail->next;
            if(InsertAfterList_DuL(ptail, pnew))
                printf("成功插入节点！\n");
            else 
            {
                printf("操作失败！\n");
                free(pnew);
                pnew = NULL;
            }
            break;
        case 0:
            break;
        default:
            printf("输入值不合法，请输入正确的操作编号");
            break;
        }
    }while(choice_num != 0);
}
