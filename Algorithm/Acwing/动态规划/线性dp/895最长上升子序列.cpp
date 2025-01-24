#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e3 + 10;
int a[N], dp[N]; // dp[i] : 以第i个数结尾的最大上升子序列长度
int n, ans = -1e9;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    a[0] = -1e9;
    std::fill(dp + 1, dp + n + 1, 1); // 初始化为1
    for (int i = 1; i <= n; i ++ )
    {
        for ( int j = 1; j < i; j ++ )
        {
            if (a[i] > a[j] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1; // j = 0, 1, 2, .. i - 1
                if(ans < dp[i])
                {
                    ans = dp[i];
                }
            }
        }
    }
    cout << ans;
    return 0;
}