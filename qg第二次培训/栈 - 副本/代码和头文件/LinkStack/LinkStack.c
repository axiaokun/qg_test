#include "../head/LinkStack.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>


/**
 *  @name        : Status initLStack(LinkStack *s)
 *	@description : Init stack
 *	@param		 : LinkStack *s
 *	@return		 : Status
 *  @notice      : None
 */
Status initLStack(LinkStack *s)
{
    if (s->top != NULL)
    {
        printf("�ѳ�ʼ����\n");
        return ERROR;
    }
    s->top = (LinkStackPtr)malloc(sizeof(LinkStack));
    s->top->next = NULL;
    s->count = 0;
    return SUCCESS;
}

/**
 *  @name        : Status isEmptyLStack(LinkStack *s)
 *	@description : Judge whether the stack is empty
 *	@param		 : LinkStack *s
 *	@return		 : Status
 *  @notice      : None
 */
Status isEmptyLStack(LinkStack *s)
{
    if (s->count == 0)
        return SUCCESS;
    return ERROR;
}

/**
 *  @name        : Status getTopLStack(LinkStack *s,ElemType *e)
 *	@description : Get stack top element
 *	@param		 : LinkStack *s,ElemType *e
 *	@return		 : Status
 *  @notice      : None
 */
Status getTopLStack(LinkStack *s,ElemType *e)
{
    if (s->top == NULL || isEmptyLStack(s))
    {
        printf("δ��ʼ��ջ����ջΪ�գ�\n");
        return ERROR;
    }
    *e = s->top->data;
    return SUCCESS;
}

/**
 *  @name        : Status clearLStack(LinkStack *s)
 *	@description : Clear stack
 *	@param		 : LinkStack *s
 *	@return		 : Status
 *  @notice      : None
 */
Status clearLStack(LinkStack *s)
{
    if (s->top == NULL || isEmptyLStack(s))
    {
        printf("δ��ʼ��ջ����ջ�Ѿ�Ϊ�գ�\n");
        return ERROR;
    }
    LinkStackPtr p_free;
    while (s->count != 0)
    {
        p_free = s->top;
        s->top = s->top->next;
        s->count--;
        free(p_free);
    }
    return SUCCESS;
}

/**
 *  @name        : Status destroyLStack(LinkStack *s)
 *	@description : Destroy stack
 *	@param		 : LinkStack *s
 *	@return		 : Status
 *  @notice      : None
 */
Status destroyLStack(LinkStack *s)
{
    if (s->top == NULL)
    {
        printf("ջ�Ѿ�������!\n");
        return ERROR;
    }
    LinkStackPtr p_free;
    while (s->top != NULL)
    {
        p_free = s->top;
        s->top = s->top->next;
        free(p_free);
    }
    s->count = -1;
    return SUCCESS;
}

/**
 *  @name        : Status LStackLength(LinkStack *s,int *length)
 *	@description : Detection length
 *	@param		 : LinkStack *s,int *length
 *	@return		 : Status
 *  @notice      : None
 */
Status LStackLength(LinkStack *s,int *length)
{
    if (s->top == NULL)
    {
        printf("δ��ʼ��ջ��\n");
        return ERROR;
    }
    *length = s->count;
    return SUCCESS;
}

/**
 *  @name        : Status pushLStack(LinkStack *s,ElemType data)
 *	@description : Push
 *	@param		 : LinkStack *s,ElemType data
 *	@return		 : Status
 *  @notice      : None
 */
Status pushLStack(LinkStack *s,ElemType data)
{
    if (s->top == NULL)
    {
        printf("δ��ʼ��ջ��\n");
        return ERROR;
    }
    LinkStackPtr p_stack = (LinkStackPtr)malloc(sizeof(StackNode));
    p_stack->data = data;
    p_stack->next = s->top;
    s->top = p_stack;
    s->count++;
    return SUCCESS;
}

/**
 *  @name        : Status popLStack(LinkStack *s,ElemType *data)
 *	@description : Stack out
 *	@param		 : LinkStack *s,ElemType *data
 *	@return		 : Status
 *  @notice      : None
 */
Status popLStack(LinkStack *s,ElemType *data)
{
    if (s->top == NULL || isEmptyLStack(s))
    {
        printf("δ��ʼ��ջ����ջΪ�գ�\n");
        return ERROR;
    }
    LinkStackPtr p_next = s->top->next;
    *data = s->top->data;
    free(s->top);
    s->top = p_next;
    s->count--;
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
