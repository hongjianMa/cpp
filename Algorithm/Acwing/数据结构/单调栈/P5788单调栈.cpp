#include <iostream>
using namespace std;
const int N = 3e6 + 10;
int stk[N], tt;  // 数组模拟栈
int a[N], f[N];  // f[N]用于存答案
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = n; i >= 1; i--)
    {
        int x = a[i]; // 单调栈板子
        while (tt && a[stk[tt]] <= x) // 弹出栈顶比当前数小的
            tt--;

        if (tt) // 存答案
            f[i] = stk[tt];
        else
            f[i] = 0;
        stk[++tt] = i; // 压入栈
    }
    for (int i = 1; i <= n; i++)
        cout << f[i] << " ";
    return 0;
}