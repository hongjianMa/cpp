#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
const int N = 2e4 + 10;
// 离散化
int n, a[N], b[N];                  // a, b 数组记录左端点和右端点
int c[N * 2], d[N * 2], ctop, dtop; // c数组记录的离散之后的数组 ,d数组记录没有合并的总的数据
int f[N * 2];                       // 用来存颜色
int ans;

int bifind(int x)
{
    int l = 1, r = ctop;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (c[mid] == x)
            return mid;
        if (c[mid] < x)
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}

signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
        d[++dtop] = a[i];
        d[++dtop] = b[i];
    }
    // 去除重复元素，放入c数组
    sort(d + 1, d + 1 + dtop);
    for (int i = 1; i <= dtop; i++)
    {
        if (i == 1 || d[i] != d[i - 1])
            c[++ctop] = d[i];
    }

    for (int i = 1; i <= n; i++)
    {
        // int x = lower_bound(c + 1, c + 1 + ctop, a[i]) - c;
        // int y = lower_bound(c + 1, c + 1 + ctop, b[i]) - c;
        int x = bifind(a[i]);
        int y = bifind(b[i]);
        for (int j = x; j < y; j++)
        {
            f[j] = 1;
        }
    }

    for (int i = 1; i < ctop; i++)
    {
        if (f[i] == 1)
            ans += c[i + 1] - c[i];
    }
    cout << ans << endl;

    return 0;
}