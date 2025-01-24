#include <iostream>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m;
int a[N], diff[N], need[N];
int d[N], s[N], t[N];
bool isok(int x)
{
    std::fill(diff + 1, diff + N - 1, 0);
    for (int i = 1; i <= x; i++)
    {
        diff[s[i]] += d[i];
        diff[t[i] + 1] -= d[i];
    }
    for (int i = 1; i <= n; i++)
    {
        need[i] = need[i - 1] + diff[i];
        if (need[i] > a[i])
            return 0;
    }
    return 1;
}

signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> d[i] >> s[i] >> t[i];
    if (isok(m))
    {
        cout << 0;
        return 0;
    }
    int l = 1, r = m;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (isok(mid))
            l = mid + 1;
        else
            r = mid;
    }
    cout << "-1" << endl
         << l;

    return 0;
}