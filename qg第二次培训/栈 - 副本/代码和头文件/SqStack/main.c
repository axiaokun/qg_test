#include "../head/SqStack.h"
#include <stdio.h>
#include <stdlib.h>


int main(void){
    SqStack p_top;
    ElemType value;
    p_top.elem = NULL;
    int choice_num, len, size;
    do
    {
        show_interface();
        choice_num = judge_int();
        system("cls");
        switch (choice_num)
        {
        case 1:
            printf("������ջ�Ĵ�С��");
            scanf("%d", &size);
            if (initStack(&p_top, size))
                printf("��ʼ���ɹ���\n");
            break;

        case 2:
            if (getTopStack(&p_top, &value))
                printf("ջ��Ԫ�أ�%d\n", value);
            break;

        case 3:
            if (clearStack(&p_top))
                printf("�ɹ����ջ��\n");
            break;

        case 4:
            if (destroyStack(&p_top))
                printf("���ٳɹ���\n");
            break;

        case 5:
            if (stackLength(&p_top,&len))
                printf("ջ����Ϊ��%d\n", len);
            break;

        case 6:
            printf("������Ҫ��ջ��ֵ��");
            value = judge_int();
            if (pushStack(&p_top,value))
                printf("�ɹ���ջ��\n");
            break;
        
        case 7: 
            if (popStack(&p_top,&value))
                printf("�ɹ���ջ�� Ԫ��Ϊ%d\n", value);
            break;

        default:
            printf("��������ȷ����ֵ��\n");
            break;
        }
    }while(choice_num != 0);
}
