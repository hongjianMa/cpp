#include <iostream>
#include <string>
#include <stack>
using namespace std;

//优先级函数
bool Priority(char ch, char topch)
{
    if ((ch == '*' || ch == '/') && (topch == '+' || topch == '-'))
        return true;
    if (topch == '(')
        return true;
    return false;
}

// 中缀表达式转后缀表达式
string MiddleToEndExpr(string expr)
{
    string result;
    stack<char> s;
    for (char ch : expr)
    {
        if (ch >= '0' && ch <= '9')
        {
            result.push_back(ch);
        }
        else
        {
            if (s.empty() || ch == '(')
            {
                s.push(ch);
            }
            else
            {
                while (!s.empty())
                {
                    // 比较ch与top的优先级
                    char chtop = s.top();
                    // ch>topch
                    if (Priority(ch, chtop))
                    {
                        s.push(ch);
                        break;
                    }
                    else
                    {
                        s.pop();
                        if (chtop == ')')
                            break; // 如果遇见)，一直出栈，直到遇见(
                        result.push_back(chtop);
                    }
                }
            }
        }
    }
    // 如果符号栈还存留符号，直接输出到后缀表达式里面
    while (!s.empty())
    {
        result.push_back(s.top());
        s.pop();
    }

    return result;
}
#if 0
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
#endif

int main()
{
    cout<<MiddleToEndExpr("(1+2)*(3+4)");


    return 0;
}