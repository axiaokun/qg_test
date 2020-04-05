#include "../head/SqStack.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>


/**
 *   @name :  ��ʼ��ջ
*/
Status initStack(SqStack *s,int sizes)
{
    if (s->elem != NULL)
    {
        printf("ջ�Ѿ����ڣ�\n");
        return ERROR;
    }
    s->elem = (ElemType *)malloc(sizes * sizeof(ElemType));
    s->top = -1;
    s->size = sizes;
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
 *  @name : �õ�ջ��Ԫ��
*/
Status getTopStack(SqStack *s,ElemType *e)
{
    if (s->elem == NULL || isEmptyStack(s))
    {
        printf("δ��ʼ��ջ����ջΪ�գ�\n");
        return ERROR;
    }
    *e = s->elem[s->top];
    return SUCCESS;
}

/**
 *  @name : ���ջ
*/
Status clearStack(SqStack *s)
{
    if (s->elem == NULL || isEmptyStack(s))
    {
        printf("δ��ʼ��ջ����ջ�Ѿ�Ϊ�գ�\n");
        return ERROR;
    }
    s->top = -1;
    return SUCCESS;
}

/**
 *  @name : ����ջ
*/
Status destroyStack(SqStack *s)
{
    if (s->elem == NULL)
    {
        printf("ջ�Ѿ�������!\n");
        return ERROR;
    }
    free(s->elem);
    return SUCCESS;
}

/**
 *  @name : ���ջ�ĳ���
*/
Status stackLength(SqStack *s,int *length)
{
    if (s->elem == NULL)
    {
        printf("δ��ʼ��ջ��\n");
        return ERROR;
    }
    *length = s->top + 1;
    return SUCCESS;
}

/**
 *  @name : ��ջ
*/
Status pushStack(SqStack *s,ElemType data)
{
    if (s->elem == NULL || s->top == s->size-1)
    {
        printf("δ��ʼ��ջ����ջ�Ѿ����ˣ�\n");
        return ERROR;
    }
    s->elem[++s->top] = data;
    return SUCCESS;
}

/**
 *  @name : ��ջ
*/
Status popStack(SqStack *s,ElemType *data)
{
    if (s->elem == NULL || isEmptyStack(s))
    {
        printf("δ��ʼ��ջ����ջΪ�գ�\n");
        return ERROR;
    }
    *data = s->elem[s->top--];
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

/**
 *  @name : �����˵�
*/
void show_interface(void)
{
    printf("****************************************************\n");
    printf("*   1.��ʼ��ջ    2.�õ�ջ��Ԫ��       3.���ջ    *\n");
    printf("*   4.����ջ      5.���ջ����         6.��ջ      *\n");
    printf("*            7.��ջ            0.�˳�����          *\n");
    printf("****************************************************\n");
    printf("������Ҫ���еĲ�����");
}
