#define AQUEUE_H_INCLUDED

#define MAXQUEUE 10
#define MAXSTRING 20

typedef struct Aqueue
{
    void *data[MAXQUEUE];      //������	
	int front;
    int rear;
    size_t length;        //���г���
} AQueue;

enum datatype {
	Int = 1,
	Char = 2,
	Float = 3,
	Double = 4  //�ĸ�����
};

typedef struct Mydata
{
	int INT;
	char CHAR;
	float FLOAT;
	double DOULBLE;	//������	
	enum datatype type;        //���� 
}Mydata;

typedef enum
{
	FALSE = 0, TRUE = 1
} Status;

/**************************************************************
 *    Prototype Declare Section
 **************************************************************/



/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitAQueue(AQueue *Q);


/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue *Q);



/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : �������Ƿ�����
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q);

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue *Q);



/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q ����ָ��Q�����Ԫ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadAQueue(AQueue *Q, void *e);



/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : ���г���count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q);



/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ����˻�Ϊ��
 */
Status EnAQueue(AQueue *Q, void *data);



/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q);



/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q);



/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q));



/**
 *  @name        : void APrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q
 *  @notice      : None
 */
void APrint(void *q);



/**
 *  @name       :     Status isint(const AQueue *Q)
 *   @description   :   �ж϶����Ƿ��ʼ��
 *   @param      Q ����ָ��
 *   @return       :   �ɹ�-TRUE; ʧ��-FALSE
 *  @notice     :  None
*/
Status isint(const AQueue *Q);



/**
 *  @name    :     static input(Mydata *e, AQueue *Q)
 *   @description   :   ��������
 *   @param      :    e Mydataָ��  Q ����ָ��  
 *   @return    :     �ɹ�-TRUE; ʧ��-FALSE
 *  @notion    :     None
*/
Status inputdata(Mydata *e, AQueue *Q);



/**
 *  @name     :    int pchuo(void)
 *   @description   :   �ж������Ƿ�Ϊ����
 *   @param        :    ��
 *   @return      :    һ������
 *  @notion      :     None 
*/
int pchuo(void);


/**
 *  @name   :     void pho(void *e, int type)
 *   @description    :   �ж��ַ�  ������
 *   @param      :     �������ָ��e  ��������type
 *   @return       :    ��
 *  @notion       :    None 
*/
void pho(void *e, int type);

/**
 *  @name   :     void show_ui(void)
 *   @description    :   ��ӡ�˵����� 
 *   @param      :     �� 
 *   @return       :    ��
 *  @notion       :    None 
*/
void show_ui(void);
/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/



