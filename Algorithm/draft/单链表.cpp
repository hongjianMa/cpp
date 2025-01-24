#include <iostream>
using namespace std;
// 手撕单链表
template <typename E>
struct Node // 定义节点
{
    E data;        // 数据域
    Node<E> *next; // 指向下一节点
}

template <class E>
class linkList
{
public:
    linkList(); // 无参构造函数
    linkList(E a[], int n);  // 有参构造函数

private:
    Node<E> *head;
};

template <class E>
linkList<E>::linkList()  // 无参构造函数
{
    head = new Node<E>;
    head->next = nullptr;
}

template <class E>
linkList<E>::linkList(E a[], int n) // 有参构造函数
{
    int i = 0;
    Node<E> *p = head -> next;
    
}

int main()
{

    return 0;
}
