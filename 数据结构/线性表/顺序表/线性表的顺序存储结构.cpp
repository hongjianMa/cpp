#include <iostream>
using namespace std;
const int N = 100;
//顺序表的定义
class SqList
{
    public:
    int data[N];
    int length;
};

//初始化顺序表
bool InitList(SqList &L)
{
    L.length = 0;
    return true;
}

//判断顺序表是否为空
bool IsListEmpty(SqList &L)
{
    if(L.length==0) return true;
    return false;
}

//清空顺序表
void ClearList(SqList &L)
{
    L.length = 0;
    return ;
}

//查看顺序表元素的个数
int ListLength(SqList &L)
{
    return L.length;
}


//插入元素
//x:在第x位置插入，elem：插入的元素的值
bool InsertList(SqList &L,int x,int elem)
{
    if(L.length==N) return false;//顺序表已满
    if(x<1||x>L.length+1) return false;//插入位置不当,不是表头也不是表尾
    if(L.length>0)
    {
        //将位于插入元素之后的元素依次往后挪一个
        for(int i = L.length-1;i>=x-1;i--)
        {
            L.data[i+1] = L.data[i];
        }
    }
    //插入元素
    L.data[x-1] = elem;
    L.length+=1;
    return true;
}

//删除第x个元素
bool DeleteElem(SqList &L,int x)
{
    if(L.length==0) return false;//线性表为空
    if(x<1||x>L.length+1) return false;//删除位置不当,小于表头 或者大于表尾
    if(x<L.length)//如果删除的不是表尾元素
    {
        for(int i = x-1;i<=L.length;i++)
        {
            L.data[i] = L.data[i+1];
        }
    }
    L.length--;
    return true;

}

//获取第x个元素的值
int GetElem(SqList &L,int x)
{
    if(L.length==0) return 0;
    if(x<1||x>L.Length) return 0;//超过表内范围返回0值
    return L.data[x-1];
}

//打印顺序表
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
    //测试插入功能
    SqList m_L;
    InitList(m_L);
    for(int i = 0;i<10;i++)
    {
        InsertList(m_L,i+1,i);
    }
    PrintList(m_L);
    InsertList(m_L,3,10);//在第三个位置插入元素
    PrintList(m_L);
    DeleteElem(m_L,3);//删除第三个位置的元素
    PrintList(m_L);

}
int main()
{
    test01();
    return 0;
}