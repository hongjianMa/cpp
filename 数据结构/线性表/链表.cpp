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
void LinkList::CreateLinkListHead(int n)//ͷ�巨��������
{
    while(n--)
    {
        ListNode *l = new ListNode;
        cin>>l->data;//������������
        l->next = node->next;
        node->next = l;
    }
}
void LinkList::CreateLinkListBack(int n)//β�巨��������
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
//ɾ��p�ڵ�
void LinkList::removeNode(ListNode *p)
{
    if(p==NULL){
        cout<<"�ýڵ�Ϊ��"<<endl;
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
//����ĳһ���ڵ�
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

//��ӡ����
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
    cout<<"������5���ڵ��ֵ��"<<endl;
    list.CreateLinkListHead(5);
    list.PrintLinkList();
    ListNode* address=list.findNode(2);
    list.InsertNode(4,9);
    list.removeNode(address);
    list.PrintLinkList();
    return 0;
}