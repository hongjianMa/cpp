#include <iostream>

using namespace std;
const int N = 250010;
int n, stk[N], top;
int h[N], w, ans;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> w >> h[i];
    }
    for (int i = 1; i <= n; i++)
    {
        while (top > 0 && h[stk[top]] > h[i])
            top--;
        if (h[stk[top]] != h[i])
            ans++;
        stk[++top] = i;
    }
    cout << ans;

    return 0;
}