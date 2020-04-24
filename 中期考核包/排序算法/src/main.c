#include "../inc/qgsort.h"
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<malloc.h>
#include<windows.h>



int main(void)
{
    all_test();  // 算法在不同数据量下的测试
    test_100k();  // 100数据*100k次排序
    char c;
    printf("\n\n\n----按任意键结束程序-----");
    scanf("%c", &c);
    return 0;
}