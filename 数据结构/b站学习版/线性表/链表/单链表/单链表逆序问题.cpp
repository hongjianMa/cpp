#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val = 0) : data(val), next(nullptr) {}
};

class LinkList
{
public:
    LinkList()
    {
        // 初始化头节点
        head = new Node();
    }
    ~LinkList() // 利用好头节点
    {
        Node *p = head;
        while (p != nullptr)
        {
            head = head->next;
            delete p;
            p = head;
        }
    }

public:
    // 单链表尾插法
    void InsertTail(int val)
    {
        Node *r = head;
        while (r->next != nullptr)
            r = r->next;
        Node *p = new Node(val);
        r->next = p;
    }

    // 链表的头插法
    void InsertHead(int val)
    {
        Node *p = new Node(val);
        p->next = head->next;
        head->next = p;
    }

    // 链表单个节点的删除
    void Remove(int val)
    {
        // q指针在p指针的前面
        // q指针指向p->next
        // delete p
        Node *p = head->next;
        Node *q = head;
        while (p != nullptr)
        {
            if (p->data == val)
            {
                q->next = p->next;
                delete p;
                return;
            }
            else
            {
                q = p;
                p = p->next;
            }
        }
    }

    // 链表多个节点的删除
    void RemoveAll(int val)
    {
        Node *p = head->next;
        Node *q = head;
        while (p != nullptr)
        {
            if (p->data == val)
            {
                q->next = p->next;
                delete p;
                p = q->next; // 对p指针进行一个重置
            }
            else
            {
                q = p;
                p = p->next;
            }
        }
    }

    // 搜索 list
    bool Find(int val)
    {
        Node *p = head->next;
        while (p != nullptr)
        {
            if (p->data == val)
                return true;
            else
                p = p->next;
        }
        return false;
    }

    // 打印单链表
    void Show()
    {
        Node *p = head->next;
        while (p != nullptr) // 这里小细节
        {
            cout << p->data << " ";
            p = p->next;
        }
    }

private:
    friend void LinkReverse(LinkList &link);
    Node *head;
};

void LinkReverse(LinkList &link)  // 单链表逆序接口
{
    /* 先把链表断开， 然后利用头插法的特性 */
    Node *head = link.head;
    Node *p = head->next;
    if (p == nullptr)
        return;
    head->next = nullptr;  // 断开， 然后进行头插法

    while (p != nullptr)
    {
        Node *q = p->next;
        p->next = head->next;
        head->next = p;
        p = q;
    }
}

void test02()
{
    LinkList a;
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        int val = rand() % 100;
        a.InsertTail(val);
        cout << val << " ";
    }
    cout << endl;
    a.Show();
    cout << endl;
    LinkReverse(a);
    a.Show();
}
int main()
{
    test02();

    return 0;
}