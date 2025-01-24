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
        cout << endl;
    }

private:
    friend bool GetLastKNode(LinkList &link, int k, int &val);
    Node *head;
};

// 求导数第k个节点的值
bool GetLastKNode(LinkList &link, int k, int &val)
{
    if (k < 1)
        return false;
    Node *head = link.head;
    Node *prev = head;
    Node *p = head;
    for (int i = 0; i < k; i++)
    {
        p = p->next;
        if (p == nullptr)
            return false;
    }
    // 这个时候，p指向正数第k个节点
    // prev指向头节点
    while (p != nullptr)
    {
        p = p->next;
        prev = prev->next;
    }
    // 这个时候prev指向倒数第k个节点
    val = prev->data;
    return true;
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
    int k = 11, val;
    if (GetLastKNode(a, k, val))
    {
        cout << "找到了：" << val << endl;
    }
}

int main()
{
    test02();

    return 0;
}