#include <stdio.h>
#include <stdlib.h>

// 单链表节点定义
typedef struct Node
{
    int data;          // 数据域
    struct Node *next; // 指向下一个节点的指针
} Node;

// 定义单链表
typedef struct LinkList
{
    Node *head; // 指向头节点的指针
} LinkList;

// 无参构造函数，初始化一个空链表
LinkList *createLinkList()
{
    LinkList *list = (LinkList *)malloc(sizeof(LinkList)); // 分配内存给链表
    list->head = (Node *)malloc(sizeof(Node));             // 创建头节点
    list->head->next = NULL;                               // 初始化为空
    return list;
}

// 判空函数，判断链表是否为空
int isEmpty(LinkList *list)
{
    return list->head->next == NULL;
}

// 遍历并打印链表
void printList(LinkList *list)
{
    Node *p = list->head->next; // 从第一个有效节点开始
    while (p != NULL)
    {
        printf("%d ", p->data); // 输出当前节点的值
        p = p->next;            // 移动到下一个节点
    }
    printf("\n");
}

// 按位置获取元素
int getItem(LinkList *list, int i)
{
    Node *p = list->head->next;
    int count = 1;
    while (count < i && p != NULL)
    {
        p = p->next;
        count++;
    }
    if (p == NULL)
    {
        printf("查找位置错误\n");
        exit(1);
    }
    else
    {
        return p->data;
    }
}

// 获取链表长度
int getLength(LinkList *list)
{
    Node *p = list->head->next;
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

// 查找值为x的元素位置
int locate(LinkList *list, int x)
{
    Node *p = list->head->next;
    int j = 1;
    while (p != NULL && p->data != x)
    {
        p = p->next;
        j++;
    }
    if (p != NULL)
        return j; // 查找成功，返回其序号
    else
        return 0; // 查找失败，返回0
}

// 在第i个位置插入值为x的元素
void insert(LinkList *list, int i, int x)
{
    Node *p = list->head;
    int j = 0;
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
    {
        printf("插入位置异常\n");
        exit(1);
    }
    else
    {
        Node *s = (Node *)malloc(sizeof(Node)); // 创建新节点
        s->data = x;                            // 新节点的数据域赋值
        s->next = p->next;                      // 将新节点的next指针指向插入位置的后续节点
        p->next = s;                            // 将插入位置前节点的next指针指向新节点
    }
}

// 按位置删除元素，并返回其值
int removeItem(LinkList *list, int i)
{
    Node *p = list->head;
    int j = 0;
    while (j < i - 1 && p != NULL)
    {
        p = p->next;
        j++;
    }
    if (p == NULL || p->next == NULL)
    {
        printf("删除位置异常\n");
        exit(1);
    }
    else
    {
        Node *q = p->next;
        int x = q->data;
        p->next = q->next;
        free(q); // 释放被删除节点的内存
        return x;
    }
}

// 使用尾插法构造链表
LinkList *createLinkListWithArray(int a[], int n)
{
    LinkList *list = (LinkList *)malloc(sizeof(LinkList)); // 分配内存给链表
    list->head = (Node *)malloc(sizeof(Node));             // 创建头节点
    list->head->next = NULL;
    Node *rear = list->head; // 定义尾指针
    for (int i = 0; i < n; i++)
    {
        Node *s = (Node *)malloc(sizeof(Node)); // 创建新节点
        s->data = a[i];
        s->next = NULL;
        rear->next = s; // 将尾节点的next指针指向新节点
        rear = s;       // 更新尾指针
    }
    return list;
}

// 析构函数，释放链表内存
void destroyLinkList(LinkList *list)
{
    Node *p = list->head;
    while (p != NULL)
    {
        Node *q = p;
        p = p->next;
        free(q); // 释放节点内存
    }
    free(list); // 释放链表结构体内存
}

// 主函数测试代码
int main()
{
    int arr[] = {10, 20, 30, 40, 50};

    // 使用数组创建链表
    LinkList *list = createLinkListWithArray(arr, 5);

    // 测试 printList()
    printf("初始链表: ");
    printList(list); // 输出: 10 20 30 40 50

    // 测试 getLength()
    printf("链表长度: %d\n", getLength(list)); // 输出: 5

    // 测试 getItem()
    printf("链表第3个位置的元素: %d\n", getItem(list, 3)); // 输出: 30

    // 测试 locate()
    int position = locate(list, 20);
    if (position != 0)
        printf("元素20的位置: %d\n", position); // 输出: 2
    else
        printf("未找到元素20\n");

    // 测试 insert()
    insert(list, 2, 15);
    printf("在第2个位置插入15后的链表: ");
    printList(list); // 输出: 10 15 20 30 40 50

    // 测试 removeItem()
    int removedElement = removeItem(list, 4);
    printf("删除第4个位置的元素 (%d) 后的链表: ", removedElement);
    printList(list); // 输出: 10 15 20 40 50

    // 测试判空
    if (isEmpty(list))
        printf("链表为空\n");
    else
        printf("链表不为空\n"); // 输出: 链表不为空

    // 清空链表
    while (!isEmpty(list))
    {
        removeItem(list, 1);
    }

    // 再次测试判空
    if (isEmpty(list))
        printf("链表已清空\n"); // 输出: 链表已清空

    // 释放链表内存
    destroyLinkList(list);

    return 0;
}
