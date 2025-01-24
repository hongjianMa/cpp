#include <iostream>
using namespace std;

template <typename Element>
struct DNode // 定义双向链表节点
{
    Element data;
    DNode<Element> *next;
    DNode<Element> *prev;
};

template <typename Element>
class LinkList // 定义模板类LinkList
{
public:
    LinkList();                    // 无参构造函数，建立一个空链表
    LinkList(Element a[], int n);  // 有参构造函数，建立一个长度为n的链表
    ~LinkList();                   // 析构函数
    int getLength();               // 获取链表长度
    Element getItem(int i);        // 获取第i个位置的元素
    int locate(Element x);         // 查找元素x的位置
    void insert(int i, Element x); // 在第i个位置插入元素x
    Element remove(int i);         // 删除第i个位置的元素
    bool empty();                  // 判断链表是否为空
    void printList();              // 打印链表

private:
    DNode<Element> *head; // 头节点
};

template <class Element>
LinkList<Element>::LinkList() // 无参构造函数
{
    head = new DNode<Element>; // 创建头节点
    head->next = head;
    head->prev = head;
}

template <class Element>
bool LinkList<Element>::empty() // 判空函数
{
    return head->next == head;
}

template <class Element>
void LinkList<Element>::printList() // 打印链表
{
    DNode<Element> *p = head->next; // 使用指针遍历链表
    while (p != head)               // 当没有回到头节点时
    {
        cout << p->data << " ";
        p = p->next; // 工作指针p往后移
    }
    cout << endl;
}

template <class Element>
Element LinkList<Element>::getItem(int i) // 按照位查找元素
{
    DNode<Element> *p = head->next;
    int count = 1;
    while (count < i && p != head)
    {
        p = p->next;
        count++;
    }
    if (p == head)
        throw "查找位置错误";
    else
        return p->data;
}

template <class Element>
int LinkList<Element>::getLength() // 获取链表长度
{
    DNode<Element> *p = head->next;
    int count = 0;
    while (p != head)
    {
        count++;
        p = p->next;
    }
    return count;
}

template <class Element>
int LinkList<Element>::locate(Element x) // 查找元素x的位置
{
    DNode<Element> *p = head->next;
    int j = 1;
    while (p != head && p->data != x)
    {
        p = p->next;
        j++;
    }
    if (p != head)
        return j; // 查找成功，返回其序号
    else
        return 0; // 查找失败，返回0
}

template <class Element>
void LinkList<Element>::insert(int i, Element x) // 在第i个位置插入元素x
{
    DNode<Element> *p = head; // 从头节点开始
    int j = 0;
    while (p->next != head && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p->next == head && j < i - 1)
        throw "插入位置异常";
    else
    {
        DNode<Element> *s = new DNode<Element>; // 使用指针创建新节点
        s->data = x;
        s->prev = p;
        p->next->prev = s;
        s->next = p->next;
        p->next = s;
    }
}

template <class Element>
Element LinkList<Element>::remove(int i) // 按照位置删除元素，并返回元素的值
{
    DNode<Element> *p = head;
    int j = 0;
    while (j < i - 1 && p->next != head)
    {
        p = p->next;
        j++;
    }
    if (p->next == head)
    {
        throw "删除位置异常";
    }
    else
    {
        DNode<Element> *q = p->next;
        Element x = q->data;
        p->next = q->next;
        q->next->prev = p;
        delete q;
        return x;
    }
}

template <class Element>
LinkList<Element>::LinkList(Element a[], int n) // 尾插法
{
    head = new DNode<Element>;
    head->next = head;
    head->prev = head;
    DNode<Element> *rear = head; // 定义尾指针为指针类型
    for (int i = 0; i < n; i++)
    {
        DNode<Element> *s = new DNode<Element>; // 创建新节点
        s->data = a[i];
        s->next = rear->next;
        s->prev = rear;
        rear->next = s;
        head->prev = s; // 更新头节点的prev指向新的尾节点
        rear = s;
    }
}

template <class Element>
LinkList<Element>::~LinkList() // 析构函数
{
    DNode<Element> *p = head->next;
    while (p != head) // 正确地遍历链表并删除节点
    {
        DNode<Element> *q = p;
        p = p->next;
        delete q;
    }
    delete head; // 最后删除头节点
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};

    // 使用数组创建双向循环链表
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
