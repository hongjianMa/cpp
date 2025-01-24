#include <iostream>
#include <stack>
using namespace std;
stack<int> a;
int main()
{
    char ch;
    int s = 0;
    do
    {
        ch = getchar();
        if (ch >= '0' && ch <= '9')
            s = s * 10 + (ch - '0');
        else if (ch == '.')
        {
            a.push(s);
            s = 0;
        }
        else if (ch != '@')
        {
            int x = a.top();
            a.pop();
            int y = a.top();
            a.pop();
            switch (ch)
            {
            case '+':
                a.push(x + y);
                break;
            case '-':
                a.push(y - x);
                break;
            case '/':
                a.push(y / x);
                break;
            case '*':
                a.push(x * y);
                break;
            }
        }
        /* code */
    } while (ch != '@');
    cout << a.top() << endl;

    return 0;
}