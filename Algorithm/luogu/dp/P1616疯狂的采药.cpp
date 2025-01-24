#include <bits/stdc++.h>

using namespace std;
const int N = 1e4 + 10;
int w[N], v[N];
int t, m;
long long dp[10000010];
int main()
{
    cin >> t >> m;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d %d", &w[i], &v[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = w[i]; j <= t; j++)
        {
            dp[j] = max(dp[j], v[i] + dp[j - w[i]]);
        }
    }
    cout << dp[t];

    return 0;
}