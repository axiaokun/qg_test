# include<stdio.h>
# include<malloc.h>
# include<stdlib.h>
# include<string.h>
# include"BintryTree.h"

// 初始化空树 
Status InitBiTree(BiTree *T)
{
    (*T) = (BiTree)malloc(sizeof(BiTNode));
    if(!(*T))
    {
        printf("内存不足！\n");
        exit(-1);
    }
    (*T)->lchild = NULL;
    (*T)->rchild = NULL;
    return SUCCESS;
}

// 递归销毁树 
Status DestroyBiTree(BiTree *T)
{
    if((*T) == NULL)
        return ERROR;
    DestroyBiTree(&((*T)->lchild));
    DestroyBiTree(&((*T)->rchild));
    free(*T);
    return SUCCESS;
}

// 创建树 
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

// 先序遍历 
Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
    if(T == NULL)
        return ERROR;
    visit(T->data);
    PreOrderTraverse(T->lchild, visit);
    PreOrderTraverse(T->rchild, visit);
    return SUCCESS;
}

// 打印 
Status print(TElemType e)
{
    printf("%c", e);
    return SUCCESS;
}


// 规范输入整数 
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
            if(word[m]<'0' || word[m]>'9')  // 检查每一位上是否为0到9的字符 
            {
                printf("请输入合法数据！\n");
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
    
    // 将字符还原成数字 
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

// 中序遍历 
Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
    if(T == NULL)
        return ERROR;
    InOrderTraverse(T->lchild, visit);
    visit(T->data);
    InOrderTraverse(T->rchild, visit);
    return SUCCESS;
}

// 后序遍历 
Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
    if(T == NULL)
        return ERROR;
    PostOrderTraverse(T->lchild, visit);
    PostOrderTraverse(T->rchild, visit);
    visit(T->data);
    return SUCCESS;
}

// 按照前缀表达式创建树 
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

// 给输入的前缀表达式添加‘#’表示虚节点 
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

// 后序遍历计算表达式 
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

// 层序遍历 
Status LevelOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
    if (T == NULL)
        return ERROR;
    Queue q;  // 使用循环队列存储节点 
    q.front = q.rear = 0;
    BiTree t = T;
    q.data[q.rear] = t;
    q.rear = (q.rear + 1) % MAXSIZE;
    while(( (q.rear - q.front + MAXSIZE) % MAXSIZE ) != 0)  // 迭代条件为：队列不为空 
    {
        t = q.data[q.front];
        q.front = (q.front + 1) % MAXSIZE;
        visit(t->data);
        // 每一层的孩子从左往右依次进入，先进先出就可以按层的节点数据 
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
