#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int dp[N];
int ans = -1e9;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dp[1] = a[1];
    for (int i = 2; i <= n; i++)
    {
        dp[i] = max(a[i],dp[i-1] + a[i]);
        ans = max(ans, dp[i]);
        // cout << ans << endl;
    }
    cout << ans << endl;

    return 0;
}