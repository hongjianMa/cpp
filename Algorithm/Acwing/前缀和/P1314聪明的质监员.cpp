#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n, m, s, w[N], v[N];
int sv[N], sw[N]; // 前缀和快速求区间
int l[N], r[N];
int W, sum;
// 二分答案
int x, y;
signed main()
{
    cin >> n >> m >> s;
    W = s; // 答案
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
        y = max(y, w[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> l[i] >> r[i];
    }
    x = 1, y++;
    while (x < y)
    {
        memset(sv, 0, sizeof sv);
        memset(sw, 0, sizeof sw);
        int mid = (x + y) >> 1;
        sum = 0;
        for (int i = 1; i <= n; i++)
        {
            if (w[i] >= mid)
            {
                sw[i] = sw[i - 1] + 1;
                sv[i] = sv[i - 1] + v[i];
            }
            else
            {
                sw[i] = sw[i - 1];
                sv[i] = sv[i - 1];
            }
        }
        for (int i = 1; i <= m; i++)
        {
            sum += (sw[r[i]] - sw[l[i] - 1]) * (sv[r[i]] - sv[l[i] - 1]);
        }
        if (sum == s) // 刚好是0
        {
            W = 0;
            break;
        }
        W = min(W, abs(sum - s));
        if (sum <= s)
            y = mid;
        else if (sum > s)
            x = mid + 1;
    }
    cout << W;
    return 0;
}