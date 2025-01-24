#include <iostream>
using namespace std;
const int N = 100;
//˳���Ķ���
class SqList
{
    public:
    int data[N];
    int length;
};

//��ʼ��˳���
bool InitList(SqList &L)
{
    L.length = 0;
    return true;
}

//�ж�˳����Ƿ�Ϊ��
bool IsListEmpty(SqList &L)
{
    if(L.length==0) return true;
    return false;
}

//���˳���
void ClearList(SqList &L)
{
    L.length = 0;
    return ;
}

//�鿴˳���Ԫ�صĸ���
int ListLength(SqList &L)
{
    return L.length;
}


//����Ԫ��
//x:�ڵ�xλ�ò��룬elem�������Ԫ�ص�ֵ
bool InsertList(SqList &L,int x,int elem)
{
    if(L.length==N) return false;//˳�������
    if(x<1||x>L.length+1) return false;//����λ�ò���,���Ǳ�ͷҲ���Ǳ�β
    if(L.length>0)
    {
        //��λ�ڲ���Ԫ��֮���Ԫ����������Ųһ��
        for(int i = L.length-1;i>=x-1;i--)
        {
            L.data[i+1] = L.data[i];
        }
    }
    //����Ԫ��
    L.data[x-1] = elem;
    L.length+=1;
    return true;
}

//ɾ����x��Ԫ��
bool DeleteElem(SqList &L,int x)
{
    if(L.length==0) return false;//���Ա�Ϊ��
    if(x<1||x>L.length+1) return false;//ɾ��λ�ò���,С�ڱ�ͷ ���ߴ��ڱ�β
    if(x<L.length)//���ɾ���Ĳ��Ǳ�βԪ��
    {
        for(int i = x-1;i<=L.length;i++)
        {
            L.data[i] = L.data[i+1];
        }
    }
    L.length--;
    return true;

}

//��ȡ��x��Ԫ�ص�ֵ
int GetElem(SqList &L,int x)
{
    if(L.length==0) return 0;
    if(x<1||x>L.Length) return 0;//�������ڷ�Χ����0ֵ
    return L.data[x-1];
}

//��ӡ˳���
void PrintList(SqList &L)
{
    for(int i = 0;i<L.length;i++)
    {
        cout<<L.data[i]<<' ';
    }
    cout<<endl;
}

void test01()
{
    //���Բ��빦��
    SqList m_L;
    InitList(m_L);
    for(int i = 0;i<10;i++)
    {
        InsertList(m_L,i+1,i);
    }
    PrintList(m_L);
    InsertList(m_L,3,10);//�ڵ�����λ�ò���Ԫ��
    PrintList(m_L);
    DeleteElem(m_L,3);//ɾ��������λ�õ�Ԫ��
    PrintList(m_L);

}
int main()
{
    test01();
    return 0;
}