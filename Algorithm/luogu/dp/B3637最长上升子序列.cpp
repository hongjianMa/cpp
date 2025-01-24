#include <bits/stdc++.h>
using namespace std;
const int N = 5010;
int n, a[N], dp[N];
int ans = 1;
void solve()
{
    std::fill(dp + 1, dp + n + 1, 1);
    for (int i = 1; i <= n; i++)
    {
        // dp[i] = 1;
        for (int j = 1; j < i; j++)
        {
            if (a[j] < a[i] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
                if (dp[i] > ans)
                {
                    ans = dp[i];
                    // cout << ans << endl;
                }
            }
        }
    }
    cout << ans << endl;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    solve();

    return 0;
}

/*
dp[1] = 1
dp[2] =      if(a[2]>a[1]&&dp[2] = dp[1]+1)


*/