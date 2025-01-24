#include <iostream>

using namespace std;
// 定义双项链表节点类型
struct Node
{
    Node(int val = 0)
        : data(val), next(nullptr), pre(nullptr)
    {
    }
    int data;
    Node *next;
    Node *pre;
};

// 定义双向节点
class DoubleLink
{
public:
    DoubleLink()
    {
        head = new Node();
    }

    ~DoubleLink()
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
    // 头插法
    void InsertHead(int val)
    {
        Node *p = new Node(val);
        if (head->next!=nullptr) head->next->pre = p;
        p->next = head->next;
        head->next = p;
        p->pre = head;
    }

    // 尾插法
    void Inserttail(int val)
    {
        Node *p = head;
        while(p->next!=nullptr) p = p->next;

        Node *node = new Node(val);
        p->next = node;
        node->pre = p;

    }

    // 节点删除
    bool Remove(int val)
    {
        Node *p = head->next;
        while(p!=nullptr)
        {
            if(p->data == val)
            {
                p->pre->next = p->next;
                if(p->next!=nulptr)
                {
                    p->next->pre = p->pre;
                }
                return true;
            }
            else{
                p = p->next;
            }
        }
        return false;
    }

    //节点搜索
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

    void Show()
    {
        Node *p = head->next;
        while(p!=nullptr)
        {
            cout<<p->data<<" ";
            p = p->next;
        }
        cout<<endl;
    }

private:
    Node *head;
};
int main()
{
    DoubleLink dlink;
    dlink.InsertHead(106);
    dlink.InsertHead(204);
    dlink.InsertHead(220);
    dlink.InsertHead(20);
    dlink.InsertHead(60);
    dlink.InsertHead(770);
    dlink.Show();
    return 0;
}