#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e2 + 10;
bool st[N];
struct node
{
    int start, end;
} a[N];

bool cmp(node a, node b)
{
    return a.end < b.end;
}

int solve(node *a, int n)
{
    sort(a, a + n, cmp);
    int ans = 0;
    int lastend = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i].start >= lastend)
        {
            ans++;
            lastend = a[i].end;
        }
    }
    return ans;
}

int main()
{
    int n;
    while (cin >> n && n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].start >> a[i].end;
        }
        int res = solve(a, n);
        printf("%d", res);
    }

    return 0;
}