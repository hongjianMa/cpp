#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> PII;
// #define int long long

const int N = 2e5 + 10;
int t, a[N], c[N], n, h;
bool check(long long x)
{
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += a[i] * (x / c[i] + 1);
        // ans += a[i] * (x / c[i] + 1);
        if (ans >= h)
            return true;
    }
    if (ans >= h)
        return true;
    return false;
}
int main()
{
    cin >> t;

    while (t--)
    {
        scanf("%d %d", &h, &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &c[i]);
        }
        long long l = 0, r = 4e10;
        while (l < r)
        {
            long long mid = l + r >> 1;
            if (check(mid))
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        cout << l + 1 << endl;
    }

    return 0;
}