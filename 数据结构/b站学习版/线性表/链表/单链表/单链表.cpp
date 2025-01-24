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
    ~LinkList()  // 利用好头节点
    {
        Node *p = head;
        while(p != nullptr)
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
                p = q->next;  // 对p指针进行一个重置
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
        while(p!=nullptr)
        {
            if(p->data==val) return true;
            else p = p->next;
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
    Node *head;
};

void test01()
{
    LinkList a;
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        int val = rand() % 100;
        a.InsertHead(val);
        cout << val << " ";
    }
    cout << endl;
    a.Show();
    printf("\n下面测试删除一个节点的功能\n");
    a.InsertHead(2000);
    a.Show();
    cout << endl;
    a.Remove(2000);
    a.Show();
    cout << endl;
    a.InsertHead(2000);
    a.InsertHead(2000);
    a.InsertHead(2000);
    a.Show();
    cout << endl;
    a.RemoveAll(2000);
    a.Show();
}

int main()
{
    test01();

    return 0;
}