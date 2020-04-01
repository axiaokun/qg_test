#include "../head/linkedList.h"
#include <malloc.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>


/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
    LinkedList phead = (LinkedList)malloc(sizeof(LNode));  // �����սڵ�
    if (phead == NULL)
        return ERROR;
    phead->next = NULL;  // ��ʼ���ṹ�������ָ��
    *L = phead;
    return SUCCESS;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
    LinkedList pfree, ptail = *L;
    while (ptail != NULL)  // �����ͷ��ڴ�
    {
        pfree = ptail;
        ptail = ptail->next;
        free(pfree);
    }
    *L = NULL;
    printf("�ͷųɹ���\n");
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
    if (p == NULL)
        return ERROR;

    LinkedList pnext;  
    if (p->next != NULL)  // �ж�p����һ���ڵ��Ƿ���ڣ��������q����󻹵ý���
        pnext = p->next;
    else 
        pnext = NULL;  // �����ڵĻ�����NULL

    p->next = q;
    q->next = pnext;
    return SUCCESS;
}

/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
    if ((p == NULL) || (p->next == NULL))  // ͬʱ�ж�p�Լ�p��ڵ��Ƿ����
        return ERROR;
    LinkedList p_cat = p->next->next;
    LinkedList p_free = p->next;
    p->next = p_cat;  // ����ԭ��p����ĵڶ����ڵ�
    p_free->data = *e;
    free(p_free);
    return SUCCESS;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
    LinkedList ptail = L->next;
    while (ptail != NULL)
    {
        visit(ptail->data);
        ptail = ptail->next;
    }
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
    if (L == NULL)
        return ERROR;
    L = L->next;
    while (L != NULL)
    {
        if (L->data == e)  // �������e�����سɹ���״̬��
            return SUCCESS;
        L = L->next;
    }
    return ERROR;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
    if (*L == NULL)
        return ERROR;
    LinkedList  pnext, ptail, phead = *L;
    ptail = phead->next;  // ����ͷָ�����һλ
    phead->next = NULL;  // ͷָ��������ΪNULL
    while (ptail != NULL)
    {
        pnext = ptail->next;        /*��ߵ���Ҫ˼·������ָ�벻��������*/
        ptail->next = phead->next;  /*ͷָ��һֱָ�����µ��Ǹ��ڵ㣬�µ�*/
        phead->next = ptail;        /*�µĽڵ�ָ��ͷָ��֮ǰ����һ���ڵ�*/
        ptail = pnext;
    }
    return SUCCESS;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
    if (L == NULL || L->next == NULL)
        return ERROR;
    LinkedList fast, slow;  // ����ָ��
    fast = slow = L;
    while (fast->next != NULL && fast->next->next != NULL)  // ���ж���һ���Ƿ�ΪNULL
    {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
            return SUCCESS;
    }
    return ERROR;
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {
    assert(*L != NULL);  // ���ö���
    LinkedList p_front, p_back, phead = *L;
    assert(phead->next != NULL || phead->next->next != NULL);  // ���ֻ��һ���սڵ����ֻ��һ���ڵ㶼����ִ��
    ElemType i;
    p_back = phead->next;
    p_front = p_back->next;
    while (p_front != NULL)
    {
        if (p_front->data % 2 == 0)
        {
            i = p_back->data;
            p_back->data = p_front->data;
            p_front->data = i;
        }
        p_back = p_front;
        p_front = p_front->next;
    }
    return phead;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {
    assert(*L != NULL);
    LinkedList fast, slow;
    fast = slow = *L;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

/**
 *  @name        : void put_in(LinkedList node)
 *	@description : Enter the value of the node
 *	@param		 : node(the node in LinkedList)
 *	@return		 : None
 *  @notice      : None
 */
void put_in(LinkedList node){
    printf("����ڵ����ݣ�");
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
    for(m=0;m<len;m++)  // ���ַ�����ת��Ϊ����
    {
        for(k=0;k<j;k++)
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
    printf("-->%d", num);
}
