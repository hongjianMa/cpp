#include <bits/stdc++.h>
using namespace std;
const int N = 1010, M = 210;
const int MOD = 1000000007;
int f[2][N][M][2];
bool val = 1; 
char a[N], b[M];
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    cin >> a + 1 >> b + 1;
    f[0][0][0][0] = f[1][0][0][0] = 1;
    for (int i = 1; i <= n; i++, val ^= 1)
        for (int j = 1; j <= m; j++)
            for (int p = 1; p <= k; p++)
            {
                if (a[i] == b[j])
                {
                    f[val][j][p][0] = (f[val ^ 1][j][p][0] + f[val ^ 1][j][p][1]) % MOD;
                    f[val][j][p][1] = (f[val ^ 1][j - 1][p][1] +
                                       (f[val ^ 1][j - 1][p - 1][0] + f[val ^ 1][j - 1][p - 1][1]) % MOD) %
                                      MOD;
                }
                else
                {
                    f[val][j][p][0] = (f[val ^ 1][j][p][0] + f[val ^ 1][j][p][1]) % MOD;
                    f[val][j][p][1] = 0;
                }
            }
    cout << (f[n & 1][m][k][0] + f[n & 1][m][k][1]) % MOD;
    return 0;
}