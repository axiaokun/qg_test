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
        printf("\n\n\n\n  ******************************************************\n");  // ��������
        printf("  *  1.����������       2.��������      3.�ͷ�����       *\n");
        printf("  *  4.ͷ������Ԫ��             5.β������Ԫ��         *\n");
        printf("  *  6.����ת                         7.Ѱ���нڵ�   *\n");
        printf("  *  8.����Ԫ��      9.��תż���ڵ�                     *\n");
        printf("  *  10.�ж������Ƿ��л�         0.����(ע��Ҫ���ͷ�����)*\n");
        printf("  ******************************************************\n");
        printf("��ѡ�������ţ�");
        choice_num = judge_int();
        system("cls");
        switch(choice_num)
        {
        case 1:
            if (InitList(&phead))
                printf("�����ɹ���\n");
            else 
                printf("����ʧ�ܣ�\n");
            break;
        case 2:
            if(phead == NULL || phead->next == NULL)
                printf("�������ڻ���ֻ����һ���յ�ͷ���\n");
            else 
                TraverseList(phead, print);
            break;
        case 3:
            if(phead == NULL)
                printf("�������ڣ�\n");
            else 
                DestroyList(&phead);
            break;
        case 4:
            if(InitList(&pnew))
                put_in(pnew);
            if(InsertList(phead, pnew))
                printf("�ɹ�����ڵ㣡\n");
            else 
            {
                printf("����ʧ�ܣ�\n");
                free(pnew);
                pnew = NULL;
            }
            break;
        case 5:
            if(InitList(&pnew))
                put_in(pnew);
            if(phead == NULL)
            {
                printf("�ȴ�������\n");
                free(pnew);
                break;
            }
            ptail = phead;
            while(ptail->next != NULL)
                ptail = ptail->next;
            if(InsertList(ptail, pnew))
                printf("�ɹ�����ڵ㣡\n");
            else 
            {
                printf("����ʧ�ܣ�\n");
                free(pnew);
                pnew = NULL;
            }
            break;
        case 6:
            if(ReverseList(&phead))
                printf("��ת�ɹ���\n");
            break;
        case 7:
            ptail = FindMidNode(&phead);
            printf("�м�ڵ�Ϊ��%d\n", ptail->data);
            break;
        case 8:
        {
            printf("����Ҫ���ҵ�Ԫ�أ�");
            int num = judge_int();
            if (SearchList(phead, num))  
                printf("��������%d\n", num);
            break;
        }
        case 9:
            phead = ReverseEvenList(&phead);
            break;
        case 10:
            if (IsLoopList(phead))
                printf("��ѭ��������\n");
            else 
                printf("û��ѭ����\n");
            break;
        case 0:
            break;
        default:
            printf("����ֵ���Ϸ�����������ȷ�Ĳ������");
            break;
        }
    }while(choice_num != 0);
}
