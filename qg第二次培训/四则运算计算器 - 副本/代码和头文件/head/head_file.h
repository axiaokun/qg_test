#define MAX 100

// 前面是不使用循环，也先不使用刷新输出界面，先完善一次成功的基本框架   ok了
// 后面需要加上这些以及输入规范的判断

typedef char ElemType;

typedef enum Status
{
    ERROR = 0,
    SUCCESS = 1
} Status;

typedef struct SqStack
{
    ElemType *elem;
    int top;
    int size;
} SqStack;

int judge_int(void);//输入整数
Status input_expression(char *expression);
Status initStack(SqStack *s, int sizes);                         //初始化栈
Status destroyStack(SqStack *s);                                 //销毁栈
Status isEmptyStack(SqStack *s);                                 //判断栈是否为空
Status pushStack(SqStack *s, ElemType data);                     //入栈
Status popStack(SqStack *s, ElemType *data);                     //出栈
Status getTopStack(SqStack *s, ElemType *e);                     //得到栈顶元素
Status infix_to_suffix(char *suffix_exps, const char *infix_exps); // 将中缀表达式转为后缀表达式
Status calculation_suffix(const char *suffix_exps, int *result);// 计算后缀表达式
void add_sub(SqStack *stack, char *suffix_exps, const char *infix_exps, int *index_infix, int *index_suffix);// 中缀转化为后缀时加号和减号处理的代码
void mul_div(SqStack *stack, char *suffix_exps, const char *infix_exps, int *index_infix, int *index_suffix);// 中缀转化为后缀时乘除的处理

