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
        printf("  *  1.����������       2.��������      3.�ͷ�����       *\n");
        printf("  *  4.ͷ������Ԫ��             5.β������Ԫ��         *\n");
        printf("  *                              0.����(ע��Ҫ���ͷ�����)*\n");
        printf("  ******************************************************\n");
        printf("��ѡ�������ţ�");
        choice_num = judge_int();
        system("cls");
        switch(choice_num)
        {
        case 1:
            if (InitList_DuL(&phead))
                printf("�����ɹ���\n");
            else 
                printf("����ʧ�ܣ�\n");
            break;
        case 2:
            if(phead == NULL || phead->next == NULL)
                printf("�������ڻ���ֻ����һ���յ�ͷ���\n");
            else 
                TraverseList_DuL(phead, print);
            break;
        case 3:
            if(phead == NULL)
                printf("�������ڣ�\n");
            else 
                DestroyList_DuL(&phead);
            break;
        case 4:
            if(InitList_DuL(&pnew))
                put_in(pnew);
            if(InsertAfterList_DuL(phead, pnew))
                printf("�ɹ�����ڵ㣡\n");
            else 
            {
                printf("����ʧ�ܣ�\n");
                free(pnew);
                pnew = NULL;
            }
            break;
        case 5:
            if(InitList_DuL(&pnew))
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
            if(InsertAfterList_DuL(ptail, pnew))
                printf("�ɹ�����ڵ㣡\n");
            else 
            {
                printf("����ʧ�ܣ�\n");
                free(pnew);
                pnew = NULL;
            }
            break;
        case 0:
            break;
        default:
            printf("����ֵ���Ϸ�����������ȷ�Ĳ������");
            break;
        }
    }while(choice_num != 0);
}
