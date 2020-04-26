# include<stdio.h>
# include<malloc.h>
# include<stdlib.h>
# include<string.h>
# include"BintryTree.h"

int into_data;

int main(void)
{
    char data[MAXSIZE];
    int i;
    int empty_tree = 0; 
    BiTree T;
    while(1)
    {
        printf("\n请输入你的选择：\n\
                        1.创建空二叉树   2，创建非空二叉树（注意以#作为虚节）    3.销毁二叉树\n\
                        4.先序遍历二叉树    5.中序遍历二叉树    6. 后序遍历二叉树\n\
                        7.根据前缀表达式创建二叉树     8. 计算前缀表达式\n\
                        9.层序遍历二叉树\n ");
        i = pchuo();
        system("cls");
        printf("操作结果：\n");
        if(i<1 || i>9)
        {
            printf("请输入合法数据！\n");
            continue;
        }
        switch(i)
        {
        case 1:
        	empty_tree = 1;
            if(InitBiTree(&T))
                printf("创建成功！\n");
            else 
                printf("创建失败！\n");
            break;
        case 2:
            getchar();
            if(empty_tree == 1){
            	free(T);
            	empty_tree = 0;
			} 
            into_data = 0;
            printf("请按前序遍历输入数据：\n");
            scanf("%s", data);
            if(CreateBiTree(&T, data))
                printf("创建成功！\n");
            else 
                printf("创建失败！\n");
            break;
        case 3:
        	if(empty_tree == 1){
        		empty_tree = 0;
			}
            if(DestroyBiTree(&T))
                printf("销毁成功！\n");
            break;
        case 4:
        {
        	if(empty_tree == 1){
        		printf("您创建的是空树！\n");
        		break;
			}
            Status (*visit)(TElemType e);
            visit = print;
            if(PreOrderTraverse(T, visit))
                printf("遍历成功！\n");
            else 
                printf("遍历失败！\n");
            break;
        }
        case 5:
        {
        	if(empty_tree == 1){
        		printf("您创建的是空树！\n");
        		break;
			}
            Status (*visit)(TElemType e);
            visit = print;
            if(InOrderTraverse(T, visit))
                printf("遍历成功！\n");
            else 
                printf("遍历失败！\n");
            break;
        }
        case 6:
        {
        	if(empty_tree == 1){
        		printf("您创建的是空树！\n");
        		break;
			}
            Status (*visit)(TElemType e);
            visit = print;
            if(PostOrderTraverse(T, visit))
                printf("遍历成功！\n");
            else 
                printf("遍历失败！\n");
            break;
        }
        case 7:
        {
            getchar();
            if(empty_tree == 1){
            	free(T);
            	empty_tree = 0;
			} 
            printf("请按输入前缀表达式：\n");
            input(data);
            if(CreateBiTreeSP(&T, data))
                printf("创建成功！\n");
            else 
                printf("创建失败！\n");
            break;
        }
        case 8:
            printf("%d", Value(T));
            break;
        case 9:
        {
        	if(empty_tree == 1){
        		printf("您创建的是空树！\n");
        		break;
			}
            Status (*visit)(TElemType e);
            visit = print;
            if(LevelOrderTraverse(T, visit))
                printf("遍历成功！\n");
            else 
                printf("遍历失败！\n");
            break;
        }
        }
    }
    return 0;
}
