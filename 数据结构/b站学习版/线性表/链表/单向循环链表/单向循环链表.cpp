#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
class CircleList
{
public:
    CircleList()
    {
        head = new Node();
        head->next = head;
        tail = head;
    }
    ~CircleList()
    {
        Node *p = head->next;
        while (p != head)
        {
            head->next = p->next;
            delete p;
            p = head->next;
        }
        delete head;
    }

public:
    // 尾插法
    void InsertTail(int val)
    {
        Node *p = new Node(val);
        tail->next = p;
        p->next = head;
        tail = p;
    }

    // 头插法
    void InsertHead(int val)
    {
        Node *p = new Node(val);
        p->next = head->next;
        head->next = p;
        if (tail->next == head)
        {
            tail = p;
        }
    }

    // 删除节点
    bool Remove(int val)
    {
        Node *p = head;
        Node *q = head->next;
        while (p->next != head)
        {
            if (q->data == val)
            {
                p->next = q->next;
                delete q;
                if (p->next == head)
                {
                    tail = p;
                }
                return true;
            }
            else
            {
                q = q->next;
                p = p->next;
            }
        }
        return false;
    }

    // 查询节点
    bool Find(int val)
    {
        Node *p = head->next;
        while (p != head)
        {
            if (p->data == val)
                return true;
            p = p->next;
        }
        return false;
    }

    // 打印链表
    void Show()
    {
        Node *p = head->next;
        while (p != head)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

private:
    struct Node
    {
        int data;
        Node *next;
        Node(int val = 0) : data(val), next(nullptr) {}
    };
    Node *head;
    Node *tail;
};

int main()
{
    srand(time(NULL));
    CircleList c;
    for (int i = 0; i < 10; i++)
    {
        c.InsertTail(rand() % 100);
    }
    c.InsertTail(200);
    c.Show();
    int a = c.Find(200);
    cout << a << endl;
    c.Remove(200);
    c.Show();

    return 0;
}