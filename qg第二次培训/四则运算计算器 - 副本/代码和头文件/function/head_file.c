#include "../head/head_file.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>


Status input_expression(char *expression)
{
    gets(expression); 
    return SUCCESS;
}

Status infix_to_suffix(char *suffix_exps, const char *infix_exps) // ����׺���ʽתΪ��׺���ʽ
{
    int time_num = 0;
    SqStack stack;
    stack.elem = NULL;
    initStack(&stack, MAX / 2);
    ElemType pop_value;
    int infix_len = strlen(infix_exps), index_infix = 0, index_suffix = 0;
    while (index_infix != infix_len)
    {
        if (infix_exps[index_infix] >= '0' && infix_exps[index_infix] <= '9')
        {
            suffix_exps[index_suffix++] = '#';
            while (infix_exps[index_infix] >= '0' && infix_exps[index_infix] <= '9')
                suffix_exps[index_suffix++] = infix_exps[index_infix++];
            suffix_exps[index_suffix++] = '#';
        }
        else
        {
            switch (infix_exps[index_infix])
            {
            case '(':
                pushStack(&stack, infix_exps[index_infix++]);
                break;

            case '/':
                mul_div(&stack, suffix_exps, infix_exps, &index_infix, &index_suffix);
                break;

            case '*':
                mul_div(&stack, suffix_exps, infix_exps, &index_infix, &index_suffix);
                break;

            case '+':
                add_sub(&stack, suffix_exps, infix_exps, &index_infix, &index_suffix);
                break;

            case '-':
                add_sub(&stack, suffix_exps, infix_exps, &index_infix, &index_suffix);
                break;

            case ')':
                if (isEmptyStack(&stack))
                {
                    printf("����ı��ʽ����\n");
                    destroyStack(&stack);
                    return ERROR;
                }
                else
                {
                    getTopStack(&stack, &pop_value);
                    while (pop_value != '(')
                    {
                        popStack(&stack, &pop_value);
                        suffix_exps[index_suffix++] = pop_value;
                        if (isEmptyStack(&stack))
                        {
                            printf("����ı��ʽ����\n");
                            destroyStack(&stack);
                            return ERROR;
                        }
                        else
                            getTopStack(&stack, &pop_value);
                    }
                    if (!isEmptyStack(&stack))
                        popStack(&stack, &pop_value);
                }
                index_infix++;
                break;

            default:
                printf("������ʽ����\n");
                destroyStack(&stack);
                exit(-1);
            }
        }
    }
    while(popStack(&stack, &pop_value))
        suffix_exps[index_suffix++] = pop_value;
    suffix_exps[index_suffix] = '\0';
    destroyStack(&stack);
    return SUCCESS;
}

Status calculation_suffix(const char *suffix_exps, int *result)
{
    int stack[MAX/2], top = -1, sum = 0;
    ElemType pop_prior, pop_next, data;
    int len = strlen(suffix_exps), index = 0;
    while(index != len)
    {
        data = suffix_exps[index++];
        switch (data)
        {
        case '+':
            stack[top-1] = stack[top] + stack[top-1];
            top--;
            break;

        case '-':
            stack[top-1] = stack[top-1] - stack[top];
            top--;
            break;

        case '*':
            stack[top-1] = stack[top-1] * stack[top];
            top--;
            break;
        
        case '/':
            stack[top-1] = stack[top-1] / stack[top];
            top--;
            break;

        case '#':
            data = suffix_exps[index++];
            while(data != '#')
            {
                sum = sum*10 + (data - '0');
                data = suffix_exps[index++];
            }
            stack[++top] = sum;
            sum = 0;
            break;

        default:
            break;
        }
    }
    *result = stack[0];
    return SUCCESS;
}

// ������Ǽӷ��ͼ�����һ����ͬ�Ĵ���
void add_sub(SqStack *stack, char *suffix_exps, const char *infix_exps, int *index_infix, int *index_suffix)
{
    ElemType pop_value;
    if (isEmptyStack(stack))
        pushStack(stack, infix_exps[*index_infix]);
    else
    {
        getTopStack(stack, &pop_value);
        while (pop_value != '(')
        {
            popStack(stack, &pop_value);
            suffix_exps[(*index_suffix)++] = pop_value;
            if (isEmptyStack(stack))
                break;
            else
                getTopStack(stack, &pop_value);
        }
        pushStack(stack, infix_exps[*index_infix]);
    }
    (*index_infix)++;
}

//�����ǳ˳���
void mul_div(SqStack *stack, char *suffix_exps, const char *infix_exps, int *index_infix, int *index_suffix)
{
    ElemType pop_value;
    if (isEmptyStack(stack))
        pushStack(stack, infix_exps[*index_infix]);
    else
    {
        getTopStack(stack, &pop_value);
        while (pop_value == '*' || pop_value == '/')
        {
            popStack(stack, &pop_value);
            suffix_exps[(*index_suffix)++] = pop_value;
            if (isEmptyStack(stack))
                break;
            else
                getTopStack(stack, &pop_value);
        }
        pushStack(stack, infix_exps[*index_infix]);
    }
    (*index_infix)++;
}

/**
 *   @name :  ��ʼ��ջ
*/
Status initStack(SqStack *s, int sizes)
{
    if (s->elem != NULL)
        return ERROR;
    s->elem = (ElemType *)malloc(sizes * sizeof(ElemType));
    s->top = -1;
    s->size = sizes;
    return SUCCESS;
}

/**
 *  @name : ����ջ
*/
Status destroyStack(SqStack *s)
{
    if (s->elem == NULL)
        return ERROR;
    free(s->elem);
    return SUCCESS;
}

/**
 *   @name : �ж�ջ�Ƿ�Ϊ��
*/
Status isEmptyStack(SqStack *s)
{
    if (s->top == -1)
        return SUCCESS;
    return ERROR;
}

/**
 *  @name : ��ջ
*/
Status pushStack(SqStack *s, ElemType data)
{
    if (s->elem == NULL || s->top == s->size - 1)
        return ERROR;
    s->elem[++s->top] = data;
    return SUCCESS;
}

/**
 *  @name : ��ջ
*/
Status popStack(SqStack *s, ElemType *data)
{
    if (s->elem == NULL || isEmptyStack(s))
        return ERROR;
    *data = s->elem[s->top--];
    return SUCCESS;
}

/**
 *  @name : �õ�ջ��Ԫ��
*/
Status getTopStack(SqStack *s, ElemType *e)
{
    if (s->elem == NULL || isEmptyStack(s))
        return ERROR;
    *e = s->elem[s->top];
    return SUCCESS;
}

/**
 *  @name        : int judge_int(void)
 *	@description : Judge input type
 *	@param		 : void
 *	@return		 : int
 *  @notice      : None
 */
int judge_int(void)  // �������ĺ�������ֹ�������������ַ�
{
    int len, num = 0, arg = 1;
    char word[10];
    int m, j= 1, k;
    while(j)
    {
        scanf("%s", word);
        len = strlen(word);
        for(m = 0;m<len;m++)
        {
            if(word[m]<'0' || word[m]>'9')  // �����Ƿ��������������ַ������
            {
                printf("����������\n");
                break;
            }
            else 
            {
                if(m == len-1)
                    j = 0;
            }
        }
    }
    j = len-1;
    for(m=0;m<len;m++)
    {
        for(k=0;k<j;k++)  // ���ַ�����ת��Ϊ����
            arg *= 10;
        num += (word[m]-'0')*arg;
        arg = 1;
        j--;
    }
    return num;
} 
