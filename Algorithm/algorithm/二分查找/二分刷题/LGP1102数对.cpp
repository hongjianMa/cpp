#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
#define int long long
int n, c;
int a[N], ans = 0;
int Bifind_1(int x)
{
    int l = 0, r = n + 1;
    while (l + 1 != r)
    {
        int mid = l + r >> 1;
        if (a[mid] < x)
            l = mid;
        else
            r = mid;
    }
    if (a[r] == x)
        return r;
    else
        return -1;
}
int Bifind_2(int x)
{
    int l = 0, r = n + 1;
    while (l + 1 != r)
    {
        int mid = l + r >> 1;
        if (a[mid] <= x)
            l = mid;
        else
            r = mid;
    }
    if (a[l] == x)
        return l;
    else
        return -1;
}
signed main()
{
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        int A = a[i] + c;
        int res1 = Bifind_1(A);
        if (res1 == -1)
            continue;
        else
        {
            int res2 = Bifind_2(A);
            ans += res2 - res1 + 1;
        }
    }
    cout << ans;

    return 0;
}