#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1e6 + 10;
int a[N];
bool check(const int x, const int n, const int m)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += max(0, a[i] - x);
        if (sum >= m)
            return true;
    }
    return false;
}
signed main()
{
    int n, m;
    cin >> n >> m;
    int highest = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        highest = max(a[i], highest);
    }
    int l = 0, r = highest + 1;
    while (l + 1 != r)
    {
        int mid = l + r >> 1;
        if (check(mid, n, m))
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    cout << l;
    return 0;
}