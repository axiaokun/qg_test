#include "../head/duLinkedList.h"
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>


/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
    DuLinkedList phead = (DuLinkedList)malloc(sizeof(DuLNode));  // 创建空节点
    if (phead == NULL)
        return ERROR;
    phead->prior = phead->next = NULL;  // 初始化结构体里面的指针
    *L = phead;
    return SUCCESS;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
    if (*L == NULL)
        return;
    DuLinkedList pfree, ptail = *L;
    while (ptail != NULL)  // 遍历释放内存
    {
        pfree = ptail;
        ptail = ptail->next;
        free(pfree);
    }
    *L = NULL;
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
    if (p == NULL)
        return ERROR;

    DuLinkedList p_rior;  
    if (p->next != NULL)  // 判断p的前一个节点是否存在，如果存在q插入后还得接上
        p_rior = p->prior;
    else 
        p_rior = NULL;  // 不存在的话补上NULL

    p->prior = q;
    q->next = p;
    q->prior = p_rior;
    p_rior->next = q;
    return SUCCESS;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
    if (p == NULL)
        return ERROR;

    DuLinkedList pnext;  
    if (p->next != NULL)  // 判断p的下一个节点是否存在，如果存在q插入后还得接上
    {
        pnext = p->next;
        pnext->prior = q;
    }
    else 
        pnext = NULL;  // 不存在的话补上NULL

    p->next = q;
    q->prior = p;
    q->next = pnext;
    return SUCCESS;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
    if ((p == NULL) || (p->next == NULL))  // 同时判断p以及p后节点是否存在
        return ERROR;
    DuLinkedList p_cat = p->next->next;
    DuLinkedList p_free = p->next;
    p_free->data = *e;
    if (p_cat != NULL)
    {
        p->next = p_cat;  // 接上原来p后面的第二个节点
        p_cat->prior = p;
    }
    else 
        p->next = p_cat;
    free(p_free);
    return SUCCESS;
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
    assert(L != NULL);
    DuLinkedList ptail = L->next;
    while (ptail != NULL)
    {
        visit(ptail->data);
        ptail = ptail->next;
    }
}

/**
 *  @name        : void put_in(DuLinkedList node)
 *	@description : Enter the value of the node
 *	@param		 : node(the node in DuLinkedList)
 *	@return		 : None
 *  @notice      : None
 */
void put_in(DuLinkedList node){
    printf("输入节点数据：");
    ElemType num = judge_int();
    node->data = num;
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
 *  @name        : void print(ElemType num)
 *	@description : print the num in the node
 *	@param		 : num(ElemType num)
 *	@return		 : None
 *  @notice      : None
 */
void print(ElemType num){
    printf("<-->%d", num);
}
