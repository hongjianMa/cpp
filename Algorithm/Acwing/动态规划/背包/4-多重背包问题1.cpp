#include<iostream>
#include <algorithm>
using namespace std;
int v[110], w[110], s[110];
int f[110][110];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ )
    {
        cin >> v[i] >> w[i] >> s[i];
    }
    for (int i = 1;i <= n; i ++ )
    {
        for (int j = 0; j <= m; j++ )
        {
            for (int k = 0; k <= s[i] && j >= k * v[i]; k++)
            {
                f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);
            }
        }
    }
    cout << f[n][m];


    return 0;
}