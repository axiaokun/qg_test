#include "../head/linkedList.h"
#include <malloc.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
    LinkedList phead, pnew, ptail;
    phead = pnew = NULL;
    int choice_num;
    do 
    {
        printf("\n\n\n\n  ******************************************************\n");  // 交互界面
        printf("  *  1.创建空链表       2.遍历链表      3.释放链表       *\n");
        printf("  *  4.头部插入元素             5.尾部插入元素         *\n");
        printf("  *  6.链表反转                         7.寻找中节点   *\n");
        printf("  *  8.查找元素      9.反转偶数节点                     *\n");
        printf("  *  10.判断链表是否有环         0.结束(注意要先释放链表)*\n");
        printf("  ******************************************************\n");
        printf("请选择操作编号：");
        choice_num = judge_int();
        system("cls");
        switch(choice_num)
        {
        case 1:
            if (InitList(&phead))
                printf("创建成功！\n");
            else 
                printf("创建失败！\n");
            break;
        case 2:
            if(phead == NULL || phead->next == NULL)
                printf("链表不存在或者只存在一个空的头结点\n");
            else 
                TraverseList(phead, print);
            break;
        case 3:
            if(phead == NULL)
                printf("链表不存在！\n");
            else 
                DestroyList(&phead);
            break;
        case 4:
            if(InitList(&pnew))
                put_in(pnew);
            if(InsertList(phead, pnew))
                printf("成功插入节点！\n");
            else 
            {
                printf("操作失败！\n");
                free(pnew);
                pnew = NULL;
            }
            break;
        case 5:
            if(InitList(&pnew))
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
            if(InsertList(ptail, pnew))
                printf("成功插入节点！\n");
            else 
            {
                printf("操作失败！\n");
                free(pnew);
                pnew = NULL;
            }
            break;
        case 6:
            if(ReverseList(&phead))
                printf("反转成功！\n");
            break;
        case 7:
            ptail = FindMidNode(&phead);
            printf("中间节点为：%d\n", ptail->data);
            break;
        case 8:
        {
            printf("输入要查找的元素：");
            int num = judge_int();
            if (SearchList(phead, num))  
                printf("存在数字%d\n", num);
            break;
        }
        case 9:
            phead = ReverseEvenList(&phead);
            break;
        case 10:
            if (IsLoopList(phead))
                printf("有循环！！！\n");
            else 
                printf("没有循环！\n");
            break;
        case 0:
            break;
        default:
            printf("输入值不合法，请输入正确的操作编号");
            break;
        }
    }while(choice_num != 0);
}
