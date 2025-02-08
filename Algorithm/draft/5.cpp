#include <bits/stdc++.h>
using namespace std;

typedef pair<double, double> PDD;
const int MAXN = 15;
const double INF = 1e18;

int n;
PDD a[MAXN + 1];                // 奶酪的坐标
double dp[MAXN + 1][1 << MAXN]; // DP数组：dp[i][k] 表示在状态k下，最后访问的点是i的最短距离

double distance(PDD x, PDD y)
{
    return sqrt((x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second));
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }

    // 初始化DP数组
    for (int i = 1; i <= n; i++)
    {
        for (int k = 0; k < (1 << n); k++)
        {
            dp[i][k] = INF; // 初始化为无穷大
        }
    }

    // 起点是 (0, 0)，初始化从起点到每个奶酪的距离
    for (int i = 1; i <= n; i++)
    {
        dp[i][1 << (i - 1)] = distance({0, 0}, a[i]);
    }

    // 状态转移
    for (int k = 1; k < (1 << n); k++)
    { // 枚举所有状态
        for (int i = 1; i <= n; i++)
        { // 枚举当前最后访问的点
            if (!(k & (1 << (i - 1))))
                continue; // 状态k不包含点i，跳过
            for (int j = 1; j <= n; j++)
            { // 枚举上一个访问的点
                if (i == j || !(k & (1 << (j - 1))))
                    continue; // 点j未被访问或与i相同，跳过
                dp[i][k] = min(dp[i][k], dp[j][k - (1 << (i - 1))] + distance(a[i], a[j]));
            }
        }
    }

    // 计算最终结果
    double ans = INF;
    for (int i = 1; i <= n; i++)
    {
        ans = min(ans, dp[i][(1 << n) - 1]); // 所有奶酪都被访问的状态是 (1 << n) - 1
    }

    printf("%.2lf\n", ans);
    return 0;
}