#include "../inc/qgsort.h"
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<malloc.h>
#include<windows.h>


// 获取某一位数的数值，digit为位数（0表示个位数）----桶排序辅助函数
int get_digit(int num, int digit)
{
    int base_num = 1;
    for(int i=0;i<digit;i++)
        base_num *= 10;
    return num / base_num % 10;
}

// 产生随机数---测试辅助函数
void rand_num(int seed, int size, int *a, int max,  int min)
{
    srand(seed);
    for(int i=0;i<size;i++)
        a[i] = rand() % (max - min + 1) + min;
}

// 把生成的数据输入到文本中
void put_data(char *file_name, int size)
{
    int rand_array[size];
    rand_num(0, size, rand_array, 100, 0);
    FILE *fp = fopen(file_name, "w+");
    if(fp == NULL)
    {
        printf("failure!");
        return;
    }
    for(int i=0;i<size;i++)
        fprintf(fp, "%d ", rand_array[i]);
    fclose(fp);
}

// 从文本中取出数据
void get_data(char *file_name, int size, int *read_array)
{
    FILE *fp = fopen(file_name, "r");
    if(fp == NULL)
    {
        printf("failure!");
        return;
    }
    for(int i=0;i<size;i++)
        fscanf(fp, "%d", &read_array[i]);
    fclose(fp);
}

// 插入排序
void insertSort(int *a,int n)
{
    int i, change_num, index_insert;
    for(i=1;i<n;i++)
    {
        index_insert = i;
        while(index_insert != 0 && a[index_insert]<a[index_insert-1])
        {
            change_num = a[index_insert];
            a[index_insert] = a[index_insert-1];
            a[index_insert-1] = change_num;
            index_insert--;
        }
    }
}


// 归并排序（合并数组）
void MergeArray(int *a,int begin,int mid,int end,int *temp)
{
    int index = begin, index_l = begin, index_r = mid+1;

    while(index_l<=mid && index_r<=end)
    {
        if(a[index_l] < a[index_r])
            temp[index++] = a[index_l++];
        else 
            temp[index++] = a[index_r++];
    }

    while(index_l<=mid)
        temp[index++] = a[index_l++];
    while(index_r<=end)
        temp[index++] = a[index_r++];

    memcpy(a+begin, temp+begin, sizeof(int)*(end-begin+1));
}


// 归并排序
void MergeSort(int *a,int begin,int end,int *temp)
{
    if(begin >= end)
        return;
    int mid = (begin + end) / 2;

    MergeSort(a, begin, mid, temp);
    MergeSort(a, mid+1, end, temp);
    MergeArray(a, begin, mid, end, temp);
}


// 快速排序（枢轴存放）---快排辅助函数
int Partition(int *a, int begin, int end)
{
    int key = a[begin];

    while(begin < end)
    {
        while(begin < end && a[end] >= key)
            end--;
        a[begin] = a[end];

        while(begin < end && a[begin] <= key)
            begin++;
        a[end] = a[begin];
    }
    a[begin] = key;
    return begin;
}


// 快速排序（递归版）
void QuickSort_Recursion(int *a, int begin, int end)
{
    if (begin >= end)
        return;
    int mid = Partition(a, begin, end);

    QuickSort_Recursion(a, begin, mid-1);
    QuickSort_Recursion(a, mid+1, end);
}


// 非递归版
void QuickSort(int *a,int size)
{
    struct Stack
    {
        int index[size];
        int num;
    };
    struct Stack stack;
    stack.num = -1;

    stack.index[++stack.num] = 0;
    stack.index[++stack.num] = size;

    while(stack.num != -1)
    {
        int end = stack.index[stack.num--], begin = stack.index[stack.num--];
        if(begin >= end)
            continue;
            
        int left = begin, right = end, key = a[begin];

        while(left < right)
        {
            while(left < right && a[right] >= key)
                right--;
            a[left] = a[right];

            while(left < right && a[left] <= key)
                left++;
            a[right] = a[left];
        }
        a[left] = key;

        stack.index[++stack.num] = left+1;
        stack.index[++stack.num] = end;
        stack.index[++stack.num] = begin;
        stack.index[++stack.num] = left-1;
    }
}


// 计数排序(这里默认最小值为零)
void CountSort(int *a, int size , int max)
{
    int count[max+1];
    for(int i=0;i<max+1;i++)
        count[i] = 0;

    for(int i=0;i<size;i++)
        count[a[i]] += 1;
    
    int j=0;
    for(int i=0;i<max+1;i++)
    {
        while(count[i]--)
            a[j++] = i;
    }
}


// 基数计数排序
void RadixCountSort(int *a,int size)
{
    // 这部分是找出最大数以及其位数
    int max_num = 0;
    for(int i=0;i<size;i++)  
    {
        if(a[i]>max_num)
            max_num = a[i];
    }
    int max_digit = 0;
    while(max_num != 0)
    {
        max_digit++;
        max_num /= 10;
    }
    
    // 队列辅助---为每一个个位数创建“桶”
    struct Queue
    {
        int *bucket;
        int top;
        int rear;
        struct Queue *next;
    };
    struct Queue queue[10];
    for(int i=0;i<10;i++)
    {
        queue[i].bucket = (int *)malloc(sizeof(int)*size);
        queue[i].rear = queue[i].top = 0;
    }

    // 开始基数排序
    int digit_num;
    for(int i=0;i<max_digit;i++)
    {
        int index = 0;
        for(int j=0;j<size;j++)
        {
            digit_num = get_digit(a[j], i);
            queue[digit_num].bucket[queue[digit_num].rear++] = a[j];
        }
        for(int j=0;j<10;j++)
        {
            while(queue[j].rear != queue[j].top)
                a[index++] = queue[j].bucket[queue[j].top++];
        }
        for(int i=0;i<10;i++)
            queue[i].rear = queue[i].top = 0;
    }


    for(int i=0;i<10;i++)
        free(queue[i].bucket);
}


// 颜色排序
void ColorSort(int *a,int size)
{
    int change_num, p0_index = 0, p2_index = size-1, p_index = 0;
    while(p_index < p2_index)
    {
        while(a[p_index] != 1 && p_index != p0_index && p_index != p2_index)
        {
            if(a[p_index] == 0)
            {
                change_num = a[p_index];
                a[p_index] = a[p0_index];
                a[p0_index++] = change_num;
            }
            else 
            {
                change_num = a[p_index];
                a[p_index] = a[p2_index];
                a[p2_index--] = change_num;
            }
        }
        if(p_index == p2_index && a[p_index] == 0)
        {
            while(a[p_index] != 0 && p_index != p0_index)
            {
                change_num = a[p_index];
                a[p_index] = a[p0_index];
                a[p0_index++] = change_num;
            }
        }
        p_index++;
    }
}


// 找到第k小的数
int find_knum(int *a, int begin, int end, int k)
{
    if(begin >= end)
        return a[begin];
    
    int mid = Partition(a, begin, end);

    if(mid == k)
        return a[mid];
    else if(mid < k)
        return find_knum(a, mid+1, end, k);
    else 
        return find_knum(a, begin, mid-1, k);
}   

void test1(int size, char *file_name)
{
    int rand_array[size];
    // rand_num(0, size, rand_array, 100, 0);
    // put_data(file_name, size);
    get_data(file_name, size, rand_array);
    clock_t tick;

    tick = clock();
    insertSort(rand_array, size);
    printf("插入排序在大小为%d的数据下耗时为:   %ldms\n", size, clock()-tick);

    tick = clock();
    int b[size];
    MergeSort(rand_array, 0, size-1, b);
    printf("归并排序在大小为%d的数据下耗时为:   %ldms\n", size, clock()-tick);
    

    tick = clock();
    CountSort(rand_array, size, 100);
    printf("计数排序在大小为%d的数据下耗时为:  %ldms\n", size, clock()-tick);

    tick = clock();
    RadixCountSort(rand_array, size);
    printf("基数计数排序在大小为%d的数据下耗时为:   %ldms\n", size, clock()-tick);
    

    rand_num(0, size, rand_array, 2, 0);
    tick = clock();
    ColorSort(rand_array, size);
    printf("颜色排序在大小为%d的数据下耗时为:  %ldms\n", size, clock()-tick);

}

void test2(int size, char *file_name)
{
    int rand_array[size];
    // rand_num(0, size, rand_array, 100, 0);
    get_data(file_name, size, rand_array);
    clock_t tick;

    tick = clock();
    QuickSort_Recursion(rand_array, 0, size-1);
    printf("快速排序（递归版）在大小为%d的数据下耗时为:   %ldms\n", size, clock()-tick);
}

void test3(int size, char *file_name)
{
    int rand_array[size];
    put_data(file_name, size);
    get_data(file_name, size, rand_array);
    // rand_num(0, size, rand_array, 100, 0);
    clock_t tick;

    tick = clock();
    QuickSort(rand_array, size-1);
    printf("快速排序（非递归版）在大小为%d的数据下耗时为:   %ldms\n", size, clock()-tick);
}


void all_test(void)
{
    printf("\n\n\n/***********************************************************************/\n");
    printf("*             10000数据下的测试                                          *\n");
    printf("/***********************************************************************/\n");
    int size = 10000;
    char file_name1[20] = "data1e4.txt";
    test3(size, file_name1);
    test2(size, file_name1);
    test1(size, file_name1);

    printf("\n\n\n/***********************************************************************/\n");
    printf("*             50000数据下的测试                                          *\n");
    printf("/***********************************************************************/\n");
    size = 50000;
    char file_name2[20] = "data5e4.txt";
    test3(size, file_name2);
    test2(size, file_name2);
    test1(size, file_name2);

    printf("\n\n\n/***********************************************************************/\n");
    printf("*             200000数据下的测试                                          *\n");
    printf("/***********************************************************************/\n");
    size = 200000;
    char file_name3[20] = "data2e6.txt";
    test3(size, file_name3);
    test2(size, file_name3);
    test1(size, file_name3);
}

void test_100k()
{
    int size = 100;
    int test_array[size], rand_seed;
    clock_t tick, all_tick[7];
    for(int i=0;i<7;i++)
        all_tick[i] = 0;

    for(int i=0;i<1e+5;i++)
    {
        rand_seed = rand() % 100;
        rand_num(rand_seed, 100, test_array, 100, 0);

        tick = clock();
        QuickSort_Recursion(test_array, 0, size-1);
        all_tick[0] += clock()-tick;

        tick = clock();
        QuickSort(test_array, size-1);
        all_tick[1] += clock()-tick;

        tick = clock();
        insertSort(test_array, size);
        all_tick[2] += clock()-tick;

        tick = clock();
        int b[size];
        MergeSort(test_array, 0, size-1, b);
        all_tick[3] += clock()-tick;
        

        tick = clock();
        CountSort(test_array, size, 100);
        all_tick[4] += clock()-tick;


        tick = clock();
        RadixCountSort(test_array, size);
        all_tick[5] += clock()-tick;
        

        rand_num(0, size, test_array, 2, 0);
        tick = clock();
        ColorSort(test_array, size);
        all_tick[6] += clock()-tick;

    }

    printf("\n\n\n/********************************************************************************/\n");
    printf("/*                              100数据*100k次排序                             */\n");
    printf("/* 快排（递归）  快排（非递归） 插入        归并        计数     基数计数        颜色 */\n");
    for(int i=0;i<7;i++)
        printf("%10ldms", all_tick[i]);
}