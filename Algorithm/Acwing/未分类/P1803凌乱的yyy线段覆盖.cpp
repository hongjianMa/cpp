#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int ans, n;
struct node
{
    int x, y;
} a[N];
bool cmp(node a, node b)
{
    return a.y < b.y;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[i].x = x, a[i].y = y;
    }
    sort(a + 1, a + 1 + n, cmp);
    int end = -1e9;
    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i].x >= end)
        {
            ans++;
            end = a[i].y;
        }
    }
    cout << ans;
    return 0;
}