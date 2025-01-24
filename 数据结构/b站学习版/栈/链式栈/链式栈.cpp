#include <iostream>
using namespace std;

class LinkStack
{
public:
    LinkStack() : size_(0)
    {
        head = new Node;
    }
    ~LinkStack()
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
    void push(int val)
    {
        Node *p = new Node(val);
        p->next = head->next;
        head->next = p;
        size_++;
    }

    void pop()
    {
        Node *p = head->next;
        head->next = p->next;
        size_--;
    }

    bool empty()
    {
        return head->next == nullptr;
    }

    int size()
    {
        return size_;
    }

    int top()
    {
        return head->next->data;
    }

private:
    struct Node
    {
        int data;
        Node *next;
        Node(int val = 0) : data(val), next(nullptr) {}
    };
    Node *head;
    int size_;
};

int main()
{

    LinkStack s;
    int arr[] = {1, 2, 3, 22, 3, 112};
    for (int v : arr)
    {
        s.push(v);
    }
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}