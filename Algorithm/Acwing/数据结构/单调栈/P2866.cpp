// 计算一头牛可以被几头牛看见

#include <iostream>
using namespace std;
const int N = 8e4 + 10;
int n, stk[N], top = 0;
long long ans;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int h;
        cin >> h;
        while (top > 0 && h >= stk[top])
        {
            top--;
        }
        ans += top;
        top++;
        stk[top] = h;
    }
    cout << ans << endl;

    return 0;
}