#include <iostream>
#include <stack>
using namespace std;

signed main()
{
    int T;
    cin >> T;
    getchar();
    char c;
    while (T--)
    {
        stack<char> s;
        while (1)
        {
            c = getchar();
            if (c == ' ' || c == '\n')
            {
                while (!s.empty())
                {
                    printf("%c", s.top());
                    s.pop();
                }
                if (c == '\n' || c == EOF)
                    break;
                printf(" ");
            }
            else
            {
                s.push(c);
            }
            printf("\n");
        }
    }

    return 0;
}