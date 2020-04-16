#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include "../AQueue/AQueue.h"

// 初始化队列
void InitAQueue(AQueue *Q)
{
    if(Q->data[0] != NULL)
    {
        printf("队列已经初始化！");
        return;
    }
    else 
    {
        int i;
        Q->length = MAXQUEUE;  // 队列长度，注意由于使用数组进行存储的队列长度已经固定，这里的长度就是最大的长度
        for(i = 0;i<MAXQUEUE;i++)
            Q->data[i] = malloc(sizeof(Mydata));// 指针数组的每一个元素指向开辟好节点大小内存的区域
        Q->front = Q->rear = 0;
        printf("成功创建队列！\n");
    }
}

// 销毁队列
void DestoryAQueue(AQueue *Q)
{
    if(isint(Q))
    {
        int i;
        for (i=0;i<MAXQUEUE;i++)
            free(Q->data[i]);// 释放指针数组指向区域的内存
        Q->data[0] = NULL;
        printf("销毁成功！\n");
        return;
    }
    printf("销毁失败!\n");
}

// 返回队列是否满的状态
Status IsFullAQueue(const AQueue *Q)
{
    if (LengthAQueue((AQueue *)Q) == Q->length-1)// 如果队列已储存元素单位的长度等于最大长度减一，那么队列满了
        return TRUE;// 这里实现循环队列会留出一个空闲单位方便对队列进行操作
    else 
        return FALSE;
}

// 判断是否为空
Status IsEmptyAQueue(const AQueue *Q)
{
    if (LengthAQueue((AQueue *)Q) == 0) // 如果队列已储存元素单位的长度为0,那么队列为空
        return TRUE;
    else 
        return FALSE;
}

// 获得队头元素
Status GetHeadAQueue(AQueue *Q, void *e)
{
    if (isint(Q))
    {
        if (IsEmptyAQueue(Q))
        {
            printf("队列为空！\n");
            return FALSE;
        }
        else 
        {
            memcpy(e, Q->data[Q->front], sizeof(Mydata));
            return TRUE;
        }
    }
    else
        return FALSE;
}

// 计算队列已储存元素单位的长度
int LengthAQueue(AQueue *Q)
{
    return (Q->rear - Q->front + Q->length)%Q->length;
}

// 入队操作
Status EnAQueue(AQueue *Q, void *data)
{
    memcpy(Q->data[Q->rear], data, sizeof(Mydata));
    Q->rear = (Q->rear + 1)%Q->length;
    return TRUE;
}

Status isint(const AQueue *Q)
{
    if (Q->data[0] == NULL)
    {
        printf("队列不存在，请先初始化队列\n");
        return FALSE;
    }
    return TRUE;
}

// 输入数据
Status inputdata(Mydata *e, AQueue *Q)
{
    if (isint(Q))
    {
        if (IsFullAQueue((const AQueue*)Q))
        {
            printf("队列已经满了，不能再增加元素了！");
            return FALSE;
        }
        else
        {
            printf("你想要入队哪种类型：\n\
                    1. 整型    2. 字符   3. 浮点数（单精度）  4. 浮点数（双精度）\n");
            int i;
            while(1)
            {
                i = pchuo();
                if(i<1 || i>4)
                {
                    printf("请输入合法数据！\n");
                    continue;
                }
                break;
            }
            e->type = i;
            printf("请输入入队数据：");
            switch (e->type)  // 根据需要输入的类型输入数据 
            {
            case Int:
                e->INT = pchuo();
                break;
            case Char:
            {
                getchar();
                char* data;
                pho(data, e->type);
                e->CHAR = *data;
                break;
            }
            case Float:
            {
                getchar();
                float data;
                pho((void*)&data, e->type);
                e->FLOAT = data;
                break;
            }
            case Double:
            {
                getchar();
                double data;
                pho((void*)&data, e->type);
                e->DOULBLE = data;
                break;
            }
            default:
                break;
            }
            return TRUE;
        }
    }
    return FALSE;
}

// 根据节点中数据的类型打印数据
void APrint(void *q)
{
    Mydata *Q = (Mydata *)q;
    if(Q->type == Int)
        printf("-->%d", Q->INT);
    if(Q->type == Char)
        printf("-->%c", Q->CHAR);
    if(Q->type == Float)
        printf("-->%.6f", Q->FLOAT);
    if(Q->type == Double)
        printf("-->%.10lf", Q->DOULBLE);
}

// 清空队列
void ClearAQueue(AQueue *Q)
{
    if(isint(Q))
    {
        if(IsEmptyAQueue(Q))
            printf("该队列已经为空！\n");
        else 
            Q->front = Q->rear = 0;
    }
}

// 遍历队列
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
{
    if(isint(Q))
    {
        if(IsEmptyAQueue(Q))
        {
            printf("该队列为空！无法遍历\n");
            return FALSE;
        }
        else 
        {
            int i = 0;
            while(i<LengthAQueue((AQueue*)Q))
            {
                foo(Q->data[(Q->front+i)%(Q->length)]);  // 将对应节点传入对数据操作的函数中
                i++;
            }
            return TRUE;
        }
    }
    return FALSE;
}

// 出队
Status DeAQueue(AQueue *Q)
{
    if(isint(Q))
    {
        if(IsEmptyAQueue(Q))
        {
            printf("队列为空，无法出队！\n");
            return FALSE;
        }
        else 
        {
            Q->front = (Q->front+1)%Q->length;  // 实际上就是把队头指针往后移动
            return TRUE;
        }
    }
    else 
        return FALSE;
}

// 规范输入为整数
int pchuo(void)
{
    int len, num = 0, arg = 1;
    char word[MAXSTRING];
    int m, j= 1, k;
    while(j)
    {
        scanf("%s", word);
        len = strlen(word);  //输入字符串
        for(m = 0;m<len;m++)
        {
            if(word[m]<'0' || word[m]>'9')
            {
                printf("请输入合法数据！\n");  //要是出现不属于0到9的字符停止for循环重新输入
                break;
            }
            else 
            {
                if(m == len-1)
                    j = 0;  // 如果到最后都没有检查到不符合的字符就可以终止while循环
            }
        }
    }
    j = len-1;
    for(m=0;m<len;m++)  // 将字符串转变为数字
    {
        for(k=0;k<j;k++)
            arg *= 10;  
        num += (word[m]-'0')*arg;
        arg = 1;
        j--;
    }
    return num;
}

// 输入数据到e中，判断字符  浮点数
void pho(void *e, int type)
{
    int len, pop_num = 0, real_num = 0, pop_location, isok = 1;
    float arg = 1;
    double num = 0;
    char word[MAXSTRING];
    int m, j= 1, k;
    while(j)
    {
        scanf("%s", word);
        len = strlen(word);
        if(type == 2)  // 如果选择的类型为字符，执行这一段if语句里面的内容
        {
            if(len != 1)  // 由于是字符所以长度为1
            {
                printf("输入内容不合法，请重新输入！\n");
                continue;
            }
            else 
            {  // 这里只规定输入英文字母字符
                if(word[0]>'a'&&word[0]<'z' || word[0]>'A'&&word[0]<'Z')
                {
                    *(char *)e = word[0];
                    return;
                }
                else 
                {
                    printf("输入内容不合法，请重新输入！\n");
                    continue;
                }
            }
        }
        if(type == 3 || type == 4)  // 这一部分是两种精度浮点数
        {
            isok = 1;  // isok是接下来是否要将字符串转变为浮点数的条件
            for(m = 0;m<len;m++)
            {
                if(word[m]>='0' && word[m]<='9' || word[m] == '.')
                {
                    if(word[m] == '.' && m == 0)  // 开头为. 不符合一个浮点数的形式
                    {
                        printf("请输入合法数据！\n");
                        isok = 0;
                        break;
                    }
                    if(word[m] == '0' && m == 0)  // 开头为0，后面不是小数点也一样不符合
                    {
                        if(word[m+1] != '.')
                        {
                            printf("请输入合法数据！\n");
                            isok = 0;
                            break;
                        }
                    }
                    if(word[m] == '.')  // 小数点的数量大于一个也不符合
                    {
                        pop_num++;
                        if(pop_num == 2)
                        {
                            printf("请输入合法数据！");
                            isok = 0;
                            break;
                        }
                        pop_location = m;  // 储存小数点的位置，很重要
                    }
                    else
                    {
                        real_num++;
                        if(real_num == 6 && type == 3)  // 根据精度不同判断是否符合
                        {
                            printf("小数点左右有效数字总和不超过6位，请重新输入！\n");
                            isok = 0;
                            break;
                        }
                        if(real_num == 16 && type == 4)
                        {
                            printf("小数点左右有效数字总和不超过16位，请重新输入！\n");
                            isok = 0;
                            break;
                        }
                    }
                }
                else 
                {
                    printf("请输入合法数据！\n");
                    isok = 0;
                    break;
                }
            }
            if(isok)
            {  // 符合条件的就可以将字符串转变成浮点数了,注意这里利用到上面储存到的小数点的位置
                for(m=0;m<pop_location;m++)
                {
                    for(k=m;k<pop_location-1;k++)
                        arg *= 10.0;  // 不断累乘10
                    num += (word[m]-'0')*arg;  // 小数点前的数字乘以这个不断累乘10的数字
                    arg = 1;
                }
                for(m = len-1;m>pop_location;m--)
                {
                    for(k=m;k>pop_location;k--)
                        arg /= 10.0;  // 不断累除
                    num += (word[m]-'0')*arg;  // 小数点后面的数字除以这个不断累除的数字
                    arg = 1;
                }
                if(type == 3)
                {
                    *(float *)e = (float)num;
                }
                else 
                    *(double*)e = num;
                j = 0;
            }
        }
    }
}

void show_ui(void)
{
	printf("请输入您的选择\n\
            1:创建队列    2:销毁队列    3:入队   4:查看队头元素   \n\
            5.遍历队列  6.清空队列   7.出队成功 \n\
            8. 结束程序\n");
}


