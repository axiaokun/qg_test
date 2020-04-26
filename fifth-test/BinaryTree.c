# include<stdio.h>
# include<malloc.h>
# include<stdlib.h>
# include<string.h>
# include"BintryTree.h"

// ��ʼ������ 
Status InitBiTree(BiTree *T)
{
    (*T) = (BiTree)malloc(sizeof(BiTNode));
    if(!(*T))
    {
        printf("�ڴ治�㣡\n");
        exit(-1);
    }
    (*T)->lchild = NULL;
    (*T)->rchild = NULL;
    return SUCCESS;
}

// �ݹ������� 
Status DestroyBiTree(BiTree *T)
{
    if((*T) == NULL)
        return ERROR;
    DestroyBiTree(&((*T)->lchild));
    DestroyBiTree(&((*T)->rchild));
    free(*T);
    return SUCCESS;
}

// ������ 
Status CreateBiTree(BiTree *T, char* definition)
{
    if(into_data > strlen(definition)-1)
        return ERROR;
    if(definition[into_data] == '#')
    {
        into_data++;
        *T = NULL;
    }
    else 
    {
        *T = (BiTree)malloc(sizeof(BiTNode));
        if((*T) == NULL)
            exit(-1);
        (*T)->data = definition[into_data];
        into_data++;
        CreateBiTree(&(*T)->lchild, definition);
        CreateBiTree(&(*T)->rchild, definition);
    }
    return SUCCESS;
}

// ������� 
Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
    if(T == NULL)
        return ERROR;
    visit(T->data);
    PreOrderTraverse(T->lchild, visit);
    PreOrderTraverse(T->rchild, visit);
    return SUCCESS;
}

// ��ӡ 
Status print(TElemType e)
{
    printf("%c", e);
    return SUCCESS;
}


// �淶�������� 
int pchuo(void)
{
    int len, num = 0, arg = 1;
    char word[MAXSIZE];
    int m, j= 1, k;
    while(j)
    {
        scanf("%s", word);
        len = strlen(word);
        for(m = 0;m<len;m++)
        {
            if(word[m]<'0' || word[m]>'9')  // ���ÿһλ���Ƿ�Ϊ0��9���ַ� 
            {
                printf("������Ϸ����ݣ�\n");
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
    
    // ���ַ���ԭ������ 
    for(m=0;m<len;m++)
    {
        for(k=0;k<j;k++)
            arg *= 10;
        num += (word[m]-'0')*arg;
        arg = 1;
        j--;
    }
    return num;
}

// ������� 
Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
    if(T == NULL)
        return ERROR;
    InOrderTraverse(T->lchild, visit);
    visit(T->data);
    InOrderTraverse(T->rchild, visit);
    return SUCCESS;
}

// ������� 
Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
    if(T == NULL)
        return ERROR;
    PostOrderTraverse(T->lchild, visit);
    PostOrderTraverse(T->rchild, visit);
    visit(T->data);
    return SUCCESS;
}

// ����ǰ׺���ʽ������ 
Status CreateBiTreeSP(BiTree *T, char* definition)
{
    if(into_data > strlen(definition)-1)
        return ERROR;
    if(definition[into_data] == '#')
    {
        into_data++;
        *T = NULL;
    }
    else 
    {
        *T = (BiTree)malloc(sizeof(BiTNode));
        if((*T) == NULL)
            exit(-1);
        (*T)->data = definition[into_data];
        if(definition[into_data]>='0' && definition[into_data]<='9')
            (*T)->tag = 0;
        else 
            (*T)->tag = 1;
        into_data++;
        CreateBiTreeSP(&(*T)->lchild, definition);
        CreateBiTreeSP(&(*T)->rchild, definition);
    }
    return SUCCESS;
}

// �������ǰ׺���ʽ��ӡ�#����ʾ��ڵ� 
void input(char* data)
{
    int i=0;
    char ch;
    while(1)
    {
        ch = getchar();
        if(ch == '\n')
            break;
        if(ch>='0' && ch<='9')
        {
            data[i] = ch;
            data[i+1] = '#';
            data[i+2] = '#';
            i+=3;
        }
        else 
        {
            data[i] = ch;
            i++;
        }
    }
}

// �������������ʽ 
int Value(BiTree T)
{
    if(T == NULL)
        return ERROR;
    Value(T->lchild);
    Value(T->rchild);
    if(T->tag == 0)
    {
        num[top] = T->data-'0';
        top++; 
    }
    else 
    {
        switch(T->data)
        {
        case '+':
            num[top-2] = num[top-2] + num[top-1];
            top--;
            break;
        case '-':
            num[top-2] = num[top-2] - num[top-1];
            top--;
            break;
        case '*':
            num[top-2] = num[top-2] * num[top-1];
            top--;
            break;
        case '/':
            num[top-2] = num[top-2] / num[top-1];
            top--;
            break;
        }
    }
    return num[top-1];
}

// ������� 
Status LevelOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
    if (T == NULL)
        return ERROR;
    Queue q;  // ʹ��ѭ�����д洢�ڵ� 
    q.front = q.rear = 0;
    BiTree t = T;
    q.data[q.rear] = t;
    q.rear = (q.rear + 1) % MAXSIZE;
    while(( (q.rear - q.front + MAXSIZE) % MAXSIZE ) != 0)  // ��������Ϊ�����в�Ϊ�� 
    {
        t = q.data[q.front];
        q.front = (q.front + 1) % MAXSIZE;
        visit(t->data);
        // ÿһ��ĺ��Ӵ����������ν��룬�Ƚ��ȳ��Ϳ��԰���Ľڵ����� 
        if(t->lchild != NULL)
        {
            if(( (q.rear - q.front + MAXSIZE) % MAXSIZE ) == (MAXSIZE-1))
                return ERROR;
            q.data[q.rear] = t->lchild;
            q.rear = (q.rear + 1) % MAXSIZE;
        }
        if(t->rchild != NULL)
        {
            if(( (q.rear - q.front + MAXSIZE) % MAXSIZE ) == (MAXSIZE-1))
                return ERROR;
            q.data[q.rear] = t->rchild;
            q.rear = (q.rear + 1) % MAXSIZE;
        }
    }
}
