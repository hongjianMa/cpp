#include <iostream>
using namespace std;
class Node//节点类
{
    public:
    int data;
    Node *next;
    Node(int x):data(x),next(nullptr){};
};

class CirecleList
{
    public:
    CirecleList():head(nullptr),tail(nullptr){};
    ~CirecleList()//循环链表 的析构函数
    {
        if(!head) return ;//如果头节点都为空，则返回
        Node *current = head;//定义current来删除链表中的元素
        while(current->next!=head)//如果只剩下一个元素，就停下
        {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        delete current;//删除最后一个元素
    }

    void CreateList(int x)//用尾插法创建循环链表
    {
        Node* last = nullptr;//用一个指向尾部的指针
        for(int i = 1;i<=x;i++)
        {
            Node *node = new Node(i);
            if(!head)
            {
                head = node;
                last = node;
                head->next = head;//初始化时自己指向自己形成环
            }else{
                last ->next = node;
                node->next = head;//新节点指向头部，形成环
                last = node;
            }
        }
        tail = last;// 最后一个节点成为尾节点
    }

    void func(int y)//解绝约瑟夫环问题
    {
        Node *cur = head;
        Node *pre = tail;//pre是cur前一个节点
        while(cur!=cur->next)
        {
            for(int i = 1;i<y;i++){// 循环y-1次找到第y个节点的前一个节点
                pre = cur;
                cur = cur->next;
            }
            //此时cur是第y个节点
            pre->next = cur->next;//把将cur前一个节点连接到cur后一个节点
            if(cur==head)head = cur->next;//如果删除的是头节点
            if(cur==tail)tail = pre;//如果删除的是尾节点
            cout<<cur->data<<" ";
            delete cur;//删除
            cur = pre->next;//更新
        }
        cout<<cur->data<<endl;//输出最后一个元素
        delete cur;
        head = tail = nullptr;//重置头指针和尾指针
    }
    private:

    Node *head,*tail;
};


int main()
{
    int n,m;
    cin>>n>>m;
    CirecleList list;
    list.CreateList(n);
    list.func(m);
    return 0;
}