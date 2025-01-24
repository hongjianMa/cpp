#include <iostream>
#include <algorithm>
using namespace std;
const int N = 110;
int v[N], w[N];
int t, m;
int dp[N][1010];
int main()
{
    cin >> t >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j <= t; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j - w[i] >= 0)
                dp[i][j] = max(dp[i][j], dp[i-1][j - w[i]] + v[i]);
        }
    }
    cout << dp[m][t];

    return 0;
}