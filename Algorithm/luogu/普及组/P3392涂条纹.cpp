#include <bits/stdc++.h>
using namespace std;
char g[55][55];
int cnt = 999999;
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> g[i][j];
        }
    }
    for (int i = 1; i < n - 1; i++)
    {

        for (int j = i + 1; j < n; j++)
        {
            int sum = 0;

            for (int k = 1; k <= i; k++)
            {
                for (int l = 1; l <= m; l++)
                {
                    if (g[k][l] != 'W')
                        sum++;
                }
            }

            for (int k = i + 1; k <= j; k++)
            {
                for (int l = 1; l <= m; l++)
                {
                    if (g[k][l] != 'B')
                        sum++;
                }
            }

            for (int k = j + 1; k <= n; k++)
            {
                for (int l = 1; l <= m; l++)
                {
                    if (g[k][l] != 'R')
                        sum++;
                }
            }
            cnt = min(cnt, sum);
        }
    }
    cout << cnt;

    return 0;
}