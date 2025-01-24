#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int N = 1e3 + 10;
char a[N], b[N];
int f[N][N]; // 数组的值表示1--i和1--j最大公共子序列
int main()
{
    int n, m;
    cin >> n >> m >> a + 1 >> b + 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            f[i][j] = max(f[i][j - 1], f[i - 1][j]); // 状态2和状态3
            if (a[i] == b[j])
            {
                f[i][j] = f[i - 1][j - 1] + 1; // 状态4
            }
        }
    }
    cout << f[n][m];

    return 0;
}