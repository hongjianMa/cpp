#include <iostream>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode* next;
};

class LinkList
{
public:
    LinkList()
    {
        node = new ListNode;
        node->next = NULL;
    }
    ~LinkList()
    {
        delete node;
    }
    void CreateLinkListBack(int n);
	void CreateLinkListHead(int n);
	void InsertNode(const int &position,const int &elem);
	void removeNode(ListNode* p); 
	ListNode* findNode(const int value);
	void PrintLinkList();
    private:
    ListNode *node;
};
void LinkList::CreateLinkListHead(int n)//头插法创建链表
{
    while(n--)
    {
        ListNode *l = new ListNode;
        cin>>l->data;//输入插入的数据
        l->next = node->next;
        node->next = l;
    }
}
void LinkList::CreateLinkListBack(int n)//尾插法创建链表
{
    ListNode *r = node;
    while(n--)
    {
        ListNode *l = new ListNode;
        cin>>l->data;
        l->next = NULL;
        r->next = l;
        r = l;
    }
}

void LinkList::InsertNode(const int &position,const int &elem)
{
    int j = 1;
    ListNode *p = new ListNode;
    p = node->next;
    while(p&&j<position-1)
    {
        p = p->next;
        j++;
    }
    if(!p||j>position-1)
        return ;
    ListNode *q = new ListNode;
    q->data = elem;
    q->next = p->next;
    p->next = q;
}
//删除p节点
void LinkList::removeNode(ListNode *p)
{
    if(p==NULL){
        cout<<"该节点为空"<<endl;
        return ;
    }

    ListNode *temp = node;
    while(temp->next!=p)
    {
        temp = temp->next;
    }
    temp->next = p->next;
    delete p;
}
//查找某一个节点
ListNode *LinkList::findNode(const int value)
{
    ListNode *temp = node->next;
    while(temp)
    {
        if(temp->data == value)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

//打印链表
void LinkList::PrintLinkList()
{
    ListNode *temp = node->next;
    while(temp)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    LinkList list;
    cout<<"请输入5个节点的值："<<endl;
    list.CreateLinkListHead(5);
    list.PrintLinkList();
    ListNode* address=list.findNode(2);
    list.InsertNode(4,9);
    list.removeNode(address);
    list.PrintLinkList();
    return 0;
}