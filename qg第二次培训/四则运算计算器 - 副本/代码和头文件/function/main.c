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
        printf("��������׺���ʽ��");
        gets(infix_expression);
        if (infix_to_suffix(suffix_expression, infix_expression))
        {
            printf("������׺���ʽ��%s \n�����׺���ʽ��%s \n", infix_expression, suffix_expression);
            if (calculation_suffix(suffix_expression, &result))
                printf("������Ϊ��%d\n", result);
        }
        printf("����0�رճ���, �����������ּ�����\n�����룺");
        choice = judge_int();
        getchar();  // ����س��ַ�
        system("cls");
    }while(choice != 0);
    return 0;
}
