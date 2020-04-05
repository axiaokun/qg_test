#include "../head/SqStack.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>


/**
 *   @name :  初始化栈
*/
Status initStack(SqStack *s,int sizes)
{
    if (s->elem != NULL)
    {
        printf("栈已经存在！\n");
        return ERROR;
    }
    s->elem = (ElemType *)malloc(sizes * sizeof(ElemType));
    s->top = -1;
    s->size = sizes;
    return SUCCESS;
}

/**
 *   @name : 判断栈是否为空
*/
Status isEmptyStack(SqStack *s)
{   
    if (s->top == -1)
        return SUCCESS;
    return ERROR;
}

/**
 *  @name : 得到栈顶元素
*/
Status getTopStack(SqStack *s,ElemType *e)
{
    if (s->elem == NULL || isEmptyStack(s))
    {
        printf("未初始化栈或者栈为空！\n");
        return ERROR;
    }
    *e = s->elem[s->top];
    return SUCCESS;
}

/**
 *  @name : 清空栈
*/
Status clearStack(SqStack *s)
{
    if (s->elem == NULL || isEmptyStack(s))
    {
        printf("未初始化栈或者栈已经为空！\n");
        return ERROR;
    }
    s->top = -1;
    return SUCCESS;
}

/**
 *  @name : 销毁栈
*/
Status destroyStack(SqStack *s)
{
    if (s->elem == NULL)
    {
        printf("栈已经不存在!\n");
        return ERROR;
    }
    free(s->elem);
    return SUCCESS;
}

/**
 *  @name : 检测栈的长度
*/
Status stackLength(SqStack *s,int *length)
{
    if (s->elem == NULL)
    {
        printf("未初始化栈！\n");
        return ERROR;
    }
    *length = s->top + 1;
    return SUCCESS;
}

/**
 *  @name : 入栈
*/
Status pushStack(SqStack *s,ElemType data)
{
    if (s->elem == NULL || s->top == s->size-1)
    {
        printf("未初始化栈或者栈已经满了！\n");
        return ERROR;
    }
    s->elem[++s->top] = data;
    return SUCCESS;
}

/**
 *  @name : 出栈
*/
Status popStack(SqStack *s,ElemType *data)
{
    if (s->elem == NULL || isEmptyStack(s))
    {
        printf("未初始化栈或者栈为空！\n");
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
int judge_int(void)  // 防崩溃的函数，防止乱输入其他的字符
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
            if(word[m]<'0' || word[m]>'9')  // 检验是否有乱输入其他字符的情况
            {
                printf("请输入整数\n");
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
        for(k=0;k<j;k++)  // 把字符重新转换为数字
            arg *= 10;
        num += (word[m]-'0')*arg;
        arg = 1;
        j--;
    }
    return num;
} 

/**
 *  @name : 操作菜单
*/
void show_interface(void)
{
    printf("****************************************************\n");
    printf("*   1.初始化栈    2.得到栈顶元素       3.清空栈    *\n");
    printf("*   4.销毁栈      5.检测栈长度         6.入栈      *\n");
    printf("*            7.出栈            0.退出程序          *\n");
    printf("****************************************************\n");
    printf("请输入要进行的操作：");
}
