#include <iostream>
using namespace std;
int n;
int dp[60];
void solve()
{
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 4;
    for (int i = 5; i <= 55; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 3];
    }
}

int main()
{
    solve();
    while (cin >> n&&n)
    {
        cout << dp[n] << endl;
    }

    return 0;
}