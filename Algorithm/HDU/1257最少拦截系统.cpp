#include <iostream>
#include <cstring>
using namespace std;
const int N = 3e4 + 5;
int n, dp[N];
int a[N];
int LIS()
{
    memset(dp, 0, sizeof dp);
    int ans = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        int max = 0;
        for (int j = 1; j < i; j++)
        {
            if (a[i] > a[j] && dp[j] > max)
                max = dp[j];
            dp[i] = max + 1;
            if (dp[i] > ans)
                ans = dp[i];
        }
    }
    return ans;
}
int main()
{
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        cout << LIS() << endl;
    }

    return 0;
}