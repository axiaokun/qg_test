#include "../head/LinkStack.h"
#include <stdio.h>
#include <stdlib.h>


int main(void){
    LinkStack p_top;
    ElemType value;
    p_top.top = NULL;
    p_top.count = -1;
    int choice_num, len;
    do
    {
        show_interface();
        choice_num = judge_int();
        system("cls");
        switch (choice_num)
        {
        case 1:
            if (initLStack(&p_top))
                printf("��ʼ���ɹ���\n");
            break;

        case 2:
            if (getTopLStack(&p_top, &value))
                printf("ջ��Ԫ�أ�%d\n", value);
            break;

        case 3:
            if (clearLStack(&p_top))
                printf("�ɹ����ջ��\n");
            break;

        case 4:
            if (destroyLStack(&p_top))
                printf("���ٳɹ���\n");
            break;

        case 5:
            if (LStackLength(&p_top,&len))
                printf("ջ����Ϊ��%d\n", len);
            break;

        case 6:
            printf("������Ҫ��ջ��ֵ��");
            value = judge_int();
            if (pushLStack(&p_top,value))
                printf("�ɹ���ջ��\n");
            break;
        
        case 7: 
            if (popLStack(&p_top,&value))
                printf("�ɹ���ջ�� Ԫ��Ϊ%d\n", value);
            break;

        default:
            printf("��������ȷ����ֵ��\n");
            break;
        }
    }while(choice_num != 0);
}
