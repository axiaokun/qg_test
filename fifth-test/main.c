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
        printf("\n���������ѡ��\n\
                        1.�����ն�����   2�������ǿն�������ע����#��Ϊ��ڣ�    3.���ٶ�����\n\
                        4.�������������    5.�������������    6. �������������\n\
                        7.����ǰ׺���ʽ����������     8. ����ǰ׺���ʽ\n\
                        9.�������������\n ");
        i = pchuo();
        system("cls");
        printf("���������\n");
        if(i<1 || i>9)
        {
            printf("������Ϸ����ݣ�\n");
            continue;
        }
        switch(i)
        {
        case 1:
        	empty_tree = 1;
            if(InitBiTree(&T))
                printf("�����ɹ���\n");
            else 
                printf("����ʧ�ܣ�\n");
            break;
        case 2:
            getchar();
            if(empty_tree == 1){
            	free(T);
            	empty_tree = 0;
			} 
            into_data = 0;
            printf("�밴ǰ������������ݣ�\n");
            scanf("%s", data);
            if(CreateBiTree(&T, data))
                printf("�����ɹ���\n");
            else 
                printf("����ʧ�ܣ�\n");
            break;
        case 3:
        	if(empty_tree == 1){
        		empty_tree = 0;
			}
            if(DestroyBiTree(&T))
                printf("���ٳɹ���\n");
            break;
        case 4:
        {
        	if(empty_tree == 1){
        		printf("���������ǿ�����\n");
        		break;
			}
            Status (*visit)(TElemType e);
            visit = print;
            if(PreOrderTraverse(T, visit))
                printf("�����ɹ���\n");
            else 
                printf("����ʧ�ܣ�\n");
            break;
        }
        case 5:
        {
        	if(empty_tree == 1){
        		printf("���������ǿ�����\n");
        		break;
			}
            Status (*visit)(TElemType e);
            visit = print;
            if(InOrderTraverse(T, visit))
                printf("�����ɹ���\n");
            else 
                printf("����ʧ�ܣ�\n");
            break;
        }
        case 6:
        {
        	if(empty_tree == 1){
        		printf("���������ǿ�����\n");
        		break;
			}
            Status (*visit)(TElemType e);
            visit = print;
            if(PostOrderTraverse(T, visit))
                printf("�����ɹ���\n");
            else 
                printf("����ʧ�ܣ�\n");
            break;
        }
        case 7:
        {
            getchar();
            if(empty_tree == 1){
            	free(T);
            	empty_tree = 0;
			} 
            printf("�밴����ǰ׺���ʽ��\n");
            input(data);
            if(CreateBiTreeSP(&T, data))
                printf("�����ɹ���\n");
            else 
                printf("����ʧ�ܣ�\n");
            break;
        }
        case 8:
            printf("%d", Value(T));
            break;
        case 9:
        {
        	if(empty_tree == 1){
        		printf("���������ǿ�����\n");
        		break;
			}
            Status (*visit)(TElemType e);
            visit = print;
            if(LevelOrderTraverse(T, visit))
                printf("�����ɹ���\n");
            else 
                printf("����ʧ�ܣ�\n");
            break;
        }
        }
    }
    return 0;
}
