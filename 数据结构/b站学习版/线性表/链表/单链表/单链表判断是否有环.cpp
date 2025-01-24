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

// 判断链表是否存在环，并返回环的入口节点
bool IsListHasCircle(Node *head, int &val)
{
    Node *fast = head;
    Node *slow = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            fast = head;
            while (fast != slow)
            {
                fast = fast->next;
                slow = slow->next;
            }
            val = fast->data;
            return true;
        }
    }
    return false;
}

// 判断两个链表是否相交， 并返回相交节点
bool IsLinkMerge(Node *head1, Node *head2, int &val)
{
    int len1 = 0, len2 = 0;
    Node *p = head1->next;
    Node *q = head2->next;
    while (p != nullptr)
    {
        len1++;
        p = p->next;
    }
    while (q != nullptr)
    {
        len2++;
        q = q->next;
    }
    p = head1->next;  // 重新指回头节点
    q = head2->next;
    if (len1 > len2)
    {
        int dis = len1 - len2;
        while (dis-- > 0)
        {
            p = p->next;
        }
    }
    else
    {
        int dis = len2 - len1;
        while (dis-- > 0)
        {
            q = q->next;
        }
    }
    // 共同走
    while (p != nullptr && q != nullptr)
    {
        if (p == q)
        {
            val = p->data;
            return true;
        }
        p = p->next;
        q = q->next;
    }
    return false;
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

void test03()
{
    Node head;
    Node n1(25), n2(30), n3(15), n4(90);
    head.next = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n2; // 形成环
    int val;
    if (IsListHasCircle(&head, val))
        cout << "形成环！ 环的入口在于：" << val;
    else
        cout << "没有形成环";
}

void test04()
{
    Node head1;
    Node n1(25), n2(30), n3(15), n4(90), n5(100);
    head1.next = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;

    Node head2;
    head2.next = &n5;
    n5.next = &n3; // 从 n5 节点开始连接到 n3，形成相交

    int val;
    if (IsLinkMerge(&head1, &head2, val))
    {
        cout << "链表相交 ， 相交节点在于：" << val << endl;
    }
    else
    {
        cout << "没有相交" << endl;
    }
}

int main()
{
    test04();

    return 0;
}