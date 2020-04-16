#define AQUEUE_H_INCLUDED

#define MAXQUEUE 10
#define MAXSTRING 20

typedef struct Aqueue
{
    void *data[MAXQUEUE];      //数据域	
	int front;
    int rear;
    size_t length;        //队列长度
} AQueue;

enum datatype {
	Int = 1,
	Char = 2,
	Float = 3,
	Double = 4  //四个类型
};

typedef struct Mydata
{
	int INT;
	char CHAR;
	float FLOAT;
	double DOULBLE;	//数据域	
	enum datatype type;        //种类 
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
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitAQueue(AQueue *Q);


/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue *Q);



/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : 检查队列是否已满
 *    @param         Q 队列指针Q
 *    @return         : 满-TRUE; 未满-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q);

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue *Q);



/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q 队列指针Q，存放元素e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadAQueue(AQueue *Q, void *e);



/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 队列长度count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q);



/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否满了或为空
 */
Status EnAQueue(AQueue *Q, void *data);



/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q);



/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q);



/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q));



/**
 *  @name        : void APrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 *  @notice      : None
 */
void APrint(void *q);



/**
 *  @name       :     Status isint(const AQueue *Q)
 *   @description   :   判断队列是否初始化
 *   @param      Q 队列指针
 *   @return       :   成功-TRUE; 失败-FALSE
 *  @notice     :  None
*/
Status isint(const AQueue *Q);



/**
 *  @name    :     static input(Mydata *e, AQueue *Q)
 *   @description   :   输入数据
 *   @param      :    e Mydata指针  Q 队列指针  
 *   @return    :     成功-TRUE; 失败-FALSE
 *  @notion    :     None
*/
Status inputdata(Mydata *e, AQueue *Q);



/**
 *  @name     :    int pchuo(void)
 *   @description   :   判断输入是否为整数
 *   @param        :    无
 *   @return      :    一个整数
 *  @notion      :     None 
*/
int pchuo(void);


/**
 *  @name   :     void pho(void *e, int type)
 *   @description    :   判断字符  浮点数
 *   @param      :     入队数据指针e  数据类型type
 *   @return       :    无
 *  @notion       :    None 
*/
void pho(void *e, int type);

/**
 *  @name   :     void show_ui(void)
 *   @description    :   打印菜单界面 
 *   @param      :     无 
 *   @return       :    无
 *  @notion       :    None 
*/
void show_ui(void);
/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/



