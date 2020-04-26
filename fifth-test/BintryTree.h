#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED
#define MAXSIZE  10

typedef char TElemType;

typedef struct BiTNode
{
    TElemType data;
    int tag;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

typedef enum Status
{
    ERROR,
    SUCCESS
}Status;

typedef struct 
{
    BiTree data[MAXSIZE];
    int front, rear;
}Queue;


int num[MAXSIZE];
int top;

extern into_data;


/**
 *  @name        : Status InitBiTree(BiTree T);
 *  @description : ����ն�����T
 *  @param       : �����������T
 */
Status InitBiTree(BiTree *T);

/**
 *  @name        : Status DestroyBiTree(BiTree T);
 *  @description : �ݻٶ�����T
 *  @param       : �����������T
 */
Status DestroyBiTree(BiTree *T);

/**
 *  @name        : Status CreateBiTree(BiTree T, char* definition);
 *  @description : ���������T
 *  @param       : �����������T, ��������������ַ���definition
 */
Status CreateBiTree(BiTree *T, char* definition);

/**
 *  @name        : Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e));
 *  @description : �������������T
 *  @param       : �����������T, �Խ��Ĳ�������visit
 */
    Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e));


/**
 *  @name       :    Status visit(TElemType e)
 *  @description  :  ��ӡ�ڵ�Ԫ��
 *  @param     :     �ڵ�������TElemType
*/
Status print(TElemType e);

/**
 *  @name     :    int pchuo(void)
 *   @description   :   �ж������Ƿ�Ϊ����
 *   @param        :    ��
 *   @return      :    һ������
 *  @notion      :     None 
*/
int pchuo(void);

/**
 *  @name        : Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e));	
 *  @description : �������������T
 *  @param       : �����������T, �Խ��Ĳ�������visit
 */
Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e));	


/**
 *  @name        : Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType e)));
 *  @description : �������������T
 *  @param       : �����������T, �Խ��Ĳ�������visit
 */
Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType e));


/**
 *  @name        : Status LevelOrderTraverse(BiTree T, Status (*visit)(TElemType e));
 *  @description : �������������T
 *  @param       : �����������T, �Խ��Ĳ�������visit
 */
Status LevelOrderTraverse(BiTree T, Status (*visit)(TElemType e));

/**
 *  @name        : int Value(BiTree T);
 *  @description : �Թ������ǰ׺���ʽ��������ֵ
 *  @param       : �����������T
 *  @note        : ���ڽ��ṹ�������ø�Tagֵ��־������������������������
 *                 �ɸ�����Ҫ�������Ӳ���.
 */
int Value(BiTree T);

/**
 *  @name       : void input(char *data)
 *  @description: �������ǰ׺���ʽ������ڵ�
 *  @param��   �����ǰ׺���ʽ
*/
void input(char *data);


Status CreateBiTreeSP(BiTree *T, char* definition);//�ر�棬¼����ʽ
#endif // BINARYTREE_H_INCLUDED
