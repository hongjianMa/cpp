#include <iostream>
using namespace std;

// 单链表节点定义
template <typename Element>
struct Node
{
    Element data;        // 数据域
    Node<Element> *next; // 指向下一个节点的指针
};

// 定义模板类LinkList
template <typename Element>
class LinkList
{
public:
    LinkList();                    // 无参构造函数，建立一个空单链表
    LinkList(Element a[], int n);  // 有参构造函数，建立一个长度为n的单链表
    ~LinkList();                   // 析构函数，释放链表内存
    int getLength();               // 获取链表长度
    Element getItem(int i);        // 获取第i个位置的元素
    int locate(Element x);         // 查找值为x的元素位置
    void insert(int i, Element x); // 在第i个位置插入值为x的元素
    Element remove(int i);         // 删除第i个元素，并返回其值
    bool empty();                  // 判断链表是否为空
    void printList();              // 打印链表

private:
    Node<Element> *head; // 指向头节点的指针
};

// 无参构造函数，初始化一个空链表
template <class Element>
LinkList<Element>::LinkList()
{
    head = new Node<Element>; // 创建头节点
    head->next = nullptr;     // 初始化为空
}

// 判空函数，判断链表是否为空
template <class Element>
bool LinkList<Element>::empty()
{
    return head->next == nullptr;
}

// 遍历并打印链表
template <class Element>
void LinkList<Element>::printList()
{
    Node<Element> *p = head->next; // 从第一个有效节点开始
    while (p != nullptr)
    {
        cout << p->data << " "; // 输出当前节点的值
        p = p->next;            // 移动到下一个节点
    }
    cout << endl;
}

// 按位置获取元素
template <class Element>
Element LinkList<Element>::getItem(int i)
{
    Node<Element> *p = head->next;
    int count = 1;
    while (count < i && p != nullptr)
    {
        p = p->next;
        count++;
    }
    if (p == nullptr)
        throw "查找位置错误";
    else
        return p->data;
}

// 获取链表长度
template <class Element>
int LinkList<Element>::getLength()
{
    Node<Element> *p = head->next;
    int count = 0;
    while (p != nullptr)
    {
        count++;
        p = p->next;
    }
    return count;
}

// 查找值为x的元素位置
template <class Element>
int LinkList<Element>::locate(Element x)
{
    Node<Element> *p = head->next;
    int j = 1;
    while (p != nullptr && p->data != x)
    {
        p = p->next;
        j++;
    }
    if (p != nullptr)
        return j; // 查找成功，返回其序号
    else
        return 0; // 查找失败，返回0
}

// 在第i个位置插入值为x的元素
template <class Element>
void LinkList<Element>::insert(int i, Element x)
{
    Node<Element> *p = head;
    int j = 0;
    while (p != nullptr && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p == nullptr)
        throw "插入位置异常";
    else
    {
        Node<Element> *s = new Node<Element>; // 创建新节点
        s->data = x;                          // 新节点的数据域赋值
        s->next = p->next;                    // 将新节点的next指针指向插入位置的后续节点
        p->next = s;                          // 将插入位置前节点的next指针指向新节点
    }
}

// 按位置删除元素，并返回其值
template <class Element>
Element LinkList<Element>::remove(int i)
{
    Node<Element> *p = head;
    int j = 0;
    while (j < i - 1 && p != nullptr)
    {
        p = p->next;
        j++;
    }
    if (p == nullptr || p->next == nullptr)
    {
        throw "删除位置异常";
    }
    else
    {
        Node<Element> *q = p->next;
        Element x = q->data;
        p->next = q->next;
        delete q; // 释放被删除节点的内存
        return x;
    }
}

// 使用尾插法构造链表
template <class Element>
LinkList<Element>::LinkList(Element a[], int n)
{
    head = new Node<Element>; // 创建头节点
    head->next = nullptr;
    Node<Element> *rear = head; // 定义尾指针
    for (int i = 0; i < n; i++)
    {
        Node<Element> *s = new Node<Element>; // 创建新节点
        s->data = a[i];
        s->next = nullptr;
        rear->next = s; // 将尾节点的next指针指向新节点
        rear = s;       // 更新尾指针
    }
}

// 析构函数，释放链表内存
template <class Element>
LinkList<Element>::~LinkList()
{
    Node<Element> *p = head;
    while (p != nullptr)
    {
        Node<Element> *q = p;
        p = p->next;
        delete q; // 释放节点内存
    }
}

// 主函数测试代码
int main()
{
    int arr[] = {10, 20, 30, 40, 50};

    // 使用数组创建链表
    LinkList<int> list(arr, 5);

    // 测试 printList()
    cout << "初始链表: ";
    list.printList(); // 输出: 10 20 30 40 50

    // 测试 getLength()
    cout << "链表长度: " << list.getLength() << endl; // 输出: 5

    // 测试 getItem()
    try
    {
        cout << "链表第3个位置的元素: " << list.getItem(3) << endl; // 输出: 30
    }
    catch (const char *msg)
    {
        cerr << msg << endl;
    }

    // 测试 locate()
    int position = list.locate(20);
    if (position != 0)
        cout << "元素20的位置: " << position << endl; // 输出: 2
    else
        cout << "未找到元素20" << endl;

    // 测试 insert()
    try
    {
        list.insert(2, 15);
        cout << "在第2个位置插入15后的链表: ";
        list.printList(); // 输出: 10 15 20 30 40 50
    }
    catch (const char *msg)
    {
        cerr << msg << endl;
    }

    // 测试 remove()
    try
    {
        int removedElement = list.remove(4);
        cout << "删除第4个位置的元素 (" << removedElement << ") 后的链表: ";
        list.printList(); // 输出: 10 15 20 40 50
    }
    catch (const char *msg)
    {
        cerr << msg << endl;
    }

    // 测试判空
    if (list.empty())
        cout << "链表为空" << endl;
    else
        cout << "链表不为空" << endl; // 输出: 链表不为空

    // 清空链表
    while (!list.empty())
    {
        list.remove(1);
    }

    // 再次测试判空
    if (list.empty())
        cout << "链表已清空" << endl; // 输出: 链表已清空

    return 0;
}
