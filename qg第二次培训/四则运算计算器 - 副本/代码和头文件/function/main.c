#include "../head/head_file.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    int result, choice;
    char infix_expression[MAX], suffix_expression[MAX];
    do
    {
        printf("请输入中缀表达式：");
        gets(infix_expression);
        if (infix_to_suffix(suffix_expression, infix_expression))
        {
            printf("输入中缀表达式：%s \n输出后缀表达式：%s \n", infix_expression, suffix_expression);
            if (calculation_suffix(suffix_expression, &result))
                printf("计算结果为：%d\n", result);
        }
        printf("按下0关闭程序, 按下其他数字继续！\n请输入：");
        choice = judge_int();
        getchar();  // 解决回车字符
        system("cls");
    }while(choice != 0);
    return 0;
}
