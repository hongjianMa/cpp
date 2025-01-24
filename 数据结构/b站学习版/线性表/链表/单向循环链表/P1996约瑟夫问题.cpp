#include <iostream>

using namespace std;
struct Node
{
    int data;
    Node *next;
} *head, *p, *temp, *tail;

int n, m;

int main()
{
    cin >> n >> m;
    head = new Node;
    head->next = nullptr;
    tail = head;
    for (int i = 1; i <= n; i++)
    {
        p = new Node;
        p->data = i;
        p->next = nullptr;
        tail->next = p;
        tail = p;
    }
    p = head->next;
    tail->next = head->next;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < m - 1; j++)
        {
            p = p->next;
        }
        cout << p->next->data << " ";
        temp = p->next;
        p->next = temp->next;
        p = p->next;
        delete (temp);
    }
    return 0;
}