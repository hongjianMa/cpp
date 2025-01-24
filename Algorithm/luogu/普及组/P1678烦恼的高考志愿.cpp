#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N], b[N];
int n, m;
long long ans = 0;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &b[i]);
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= m; i++)
    {
        int l = 1, r = n;
        int mid;
        while (l < r)
        {
            mid = l + r >> 1;
            if (a[mid] > b[i])
                r = mid;
            else
                l = mid + 1;
        }
        if (b[i] < a[1])
            ans += a[1] - b[i];
        else
            ans += min(abs(a[l] - b[i]), abs(a[l - 1] - b[i]));
    }
    cout << ans;
    return 0;
}