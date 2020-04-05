#define MAX 100

// ǰ���ǲ�ʹ��ѭ����Ҳ�Ȳ�ʹ��ˢ��������棬������һ�γɹ��Ļ������   ok��
// ������Ҫ������Щ�Լ�����淶���ж�

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

int judge_int(void);//��������
Status input_expression(char *expression);
Status initStack(SqStack *s, int sizes);                         //��ʼ��ջ
Status destroyStack(SqStack *s);                                 //����ջ
Status isEmptyStack(SqStack *s);                                 //�ж�ջ�Ƿ�Ϊ��
Status pushStack(SqStack *s, ElemType data);                     //��ջ
Status popStack(SqStack *s, ElemType *data);                     //��ջ
Status getTopStack(SqStack *s, ElemType *e);                     //�õ�ջ��Ԫ��
Status infix_to_suffix(char *suffix_exps, const char *infix_exps); // ����׺���ʽתΪ��׺���ʽ
Status calculation_suffix(const char *suffix_exps, int *result);// �����׺���ʽ
void add_sub(SqStack *stack, char *suffix_exps, const char *infix_exps, int *index_infix, int *index_suffix);// ��׺ת��Ϊ��׺ʱ�Ӻźͼ��Ŵ���Ĵ���
void mul_div(SqStack *stack, char *suffix_exps, const char *infix_exps, int *index_infix, int *index_suffix);// ��׺ת��Ϊ��׺ʱ�˳��Ĵ���

