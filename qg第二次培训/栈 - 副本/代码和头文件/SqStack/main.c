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
            printf("请输入栈的大小：");
            scanf("%d", &size);
            if (initStack(&p_top, size))
                printf("初始化成功！\n");
            break;

        case 2:
            if (getTopStack(&p_top, &value))
                printf("栈顶元素：%d\n", value);
            break;

        case 3:
            if (clearStack(&p_top))
                printf("成功清空栈！\n");
            break;

        case 4:
            if (destroyStack(&p_top))
                printf("销毁成功！\n");
            break;

        case 5:
            if (stackLength(&p_top,&len))
                printf("栈长度为：%d\n", len);
            break;

        case 6:
            printf("请输入要入栈的值：");
            value = judge_int();
            if (pushStack(&p_top,value))
                printf("成功入栈！\n");
            break;
        
        case 7: 
            if (popStack(&p_top,&value))
                printf("成功出栈， 元素为%d\n", value);
            break;

        default:
            printf("请输入正确的数值！\n");
            break;
        }
    }while(choice_num != 0);
}
