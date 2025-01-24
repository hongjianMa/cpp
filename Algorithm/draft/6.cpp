#include <stdio.h>
#include <stdlib.h>

typedef int eletype; // 假设元素类型为整型

// 定义二叉树节点结构体
typedef struct BiTNode
{
    eletype data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// 定义栈结构体
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef struct
{
    BiTree *base, *top;
    int stacksize;
} Stack;

// 初始化栈
void InitStack(Stack *S)
{
    S->base = (BiTree *)malloc(STACK_INIT_SIZE * sizeof(BiTNode *));
    if (!S->base)
        exit(-1); // 分配失败
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
}

// 入栈
void Push(Stack *S, BiTree e)
{
    if (S->top - S->base >= S->stacksize)
    { // 栈满，追加存储空间
        S->base = (BiTree *)realloc(S->base, (STACKINCREMENT + S->stacksize) * sizeof(BiTNode *));
        if (!S->base)
            exit(-1); // 存储分配错误
        S->top = S->base + S->stacksize;
        S->stacksize += STACKINCREMENT;
    }
    *(S->top)++ = e;
}

// 出栈
BiTree Pop(Stack *S)
{
    if (S->top == S->base)
        return NULL; // 栈空
    return *(--S->top);
}

// 判断栈是否为空
int IsEmpty(Stack *S)
{
    return S->top == S->base;
}

// 先序递归法建树
void CreateBiTree(BiTree *T)
{
    eletype ch;
    scanf("%d", &ch); // 输入数据，假设以0表示空结点
    if (ch == 0)
    {
        *T = NULL;
    }
    else
    {
        *T = (BiTNode *)malloc(sizeof(BiTNode));
        (*T)->data = ch;
        CreateBiTree(&(*T)->lchild); // 递归创建左子树
        CreateBiTree(&(*T)->rchild); // 递归创建右子树
    }
}

// 中序递归遍历
void InOrderTraversal(BiTree T)
{
    if (T != NULL)
    {
        InOrderTraversal(T->lchild);
        printf("%d ", T->data);
        InOrderTraversal(T->rchild);
    }
}

// 非递归中序遍历
void InOrderNonRecursive(BiTree T)
{
    Stack S;
    InitStack(&S);
    BiTree p = T;

    while (p || !IsEmpty(&S))
    {
        while (p)
        {
            Push(&S, p);
            p = p->lchild;
        }
        if (!IsEmpty(&S))
        {
            p = Pop(&S);
            printf("%d ", p->data);
            p = p->rchild;
        }
    }
}

// 销毁二叉树（释放内存）
void DestroyBiTree(BiTree *T)
{
    if (*T)
    {
        DestroyBiTree(&(*T)->lchild);
        DestroyBiTree(&(*T)->rchild);
        free(*T);
        *T = NULL;
    }
}

int main()
{
    BiTree T = NULL;
    printf("请输入先序序列（以0作为结束标志）：\n");
    CreateBiTree(&T);

    printf("中序递归遍历输出：");
    InOrderTraversal(T);
    printf("\n");

    printf("非递归中序遍历输出：");
    InOrderNonRecursive(T);
    printf("\n");

    // 清理内存
    DestroyBiTree(&T);

    return 0;
}