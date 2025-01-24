#include <iostream>
using namespace std;
class Node//�ڵ���
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
    ~CirecleList()//ѭ������ ����������
    {
        if(!head) return ;//���ͷ�ڵ㶼Ϊ�գ��򷵻�
        Node *current = head;//����current��ɾ�������е�Ԫ��
        while(current->next!=head)//���ֻʣ��һ��Ԫ�أ���ͣ��
        {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        delete current;//ɾ�����һ��Ԫ��
    }

    void CreateList(int x)//��β�巨����ѭ������
    {
        Node* last = nullptr;//��һ��ָ��β����ָ��
        for(int i = 1;i<=x;i++)
        {
            Node *node = new Node(i);
            if(!head)
            {
                head = node;
                last = node;
                head->next = head;//��ʼ��ʱ�Լ�ָ���Լ��γɻ�
            }else{
                last ->next = node;
                node->next = head;//�½ڵ�ָ��ͷ�����γɻ�
                last = node;
            }
        }
        tail = last;// ���һ���ڵ��Ϊβ�ڵ�
    }

    void func(int y)//���Լɪ������
    {
        Node *cur = head;
        Node *pre = tail;//pre��curǰһ���ڵ�
        while(cur!=cur->next)
        {
            for(int i = 1;i<y;i++){// ѭ��y-1���ҵ���y���ڵ��ǰһ���ڵ�
                pre = cur;
                cur = cur->next;
            }
            //��ʱcur�ǵ�y���ڵ�
            pre->next = cur->next;//�ѽ�curǰһ���ڵ����ӵ�cur��һ���ڵ�
            if(cur==head)head = cur->next;//���ɾ������ͷ�ڵ�
            if(cur==tail)tail = pre;//���ɾ������β�ڵ�
            cout<<cur->data<<" ";
            delete cur;//ɾ��
            cur = pre->next;//����
        }
        cout<<cur->data<<endl;//������һ��Ԫ��
        delete cur;
        head = tail = nullptr;//����ͷָ���βָ��
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