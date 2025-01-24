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
    friend void MergeTwoLink(LinkList &link1, LinkList &link2);
    Node *head;
};

// 两个有序链表的合并

void MergeTwoLink(LinkList &link1, LinkList &link2)
{
    Node *p = link1.head->next;
    Node *q = link2.head->next;
    Node *tail = link1.head;
    link2.head = nullptr;
    while (p != nullptr && q != nullptr)
    {
        if (p->data > q->data)
        {
            tail->next = q;
            q = q->next;
            tail = tail->next;
        }
        else
        {
            tail->next = p;
            p = p->next;
            tail = tail->next;
        }
    }
    if (p != nullptr)
    {
        tail->next = p;
    }
    else
    {
        tail->next = q;
    }
}

void test02()
{
    LinkList a, b;
    int arr1[] = {1, 5, 12, 14, 29, 44};
    int arr2[] = {4, 15, 34, 44, 55, 66};
    for (int i = 0; i < sizeof arr1 / sizeof arr1[0]; i++)
    {
        a.InsertTail(arr1[i]);
    }
    for (int i = 0; i < sizeof arr2 / sizeof arr2[0]; i++)
    {
        b.InsertTail(arr2[i]);
    }
    a.Show();
    b.Show();
    MergeTwoLink(a, b);
    a.Show();
    b.Show();
}

int main()
{
    test02();

    return 0;
}