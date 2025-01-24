#include <iostream>
#include <algorithm>
using namespace std;
const int N = 510, INF = 1e9;
int n;
int g[N][N], f[N][N];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> g[i][j];
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= i + 1; j++)
        {
            f[i][j] = -INF;
        }
    }
    f[1][1] = g[1][1];
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            f[i][j] = max(f[i - 1][j], f[i - 1][j - 1]) + g[i][j];
        }
    }
    int ans = -INF;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, f[n][i]);
    }

    cout << ans;

    return 0;
}