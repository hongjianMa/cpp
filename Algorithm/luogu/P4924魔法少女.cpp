#include <iostream>

using namespace std;
const int N = 510;
int n, m, g[N][N], number;
int f[N][N]; // 临时数组
int main()
{
    int a, b, r, z;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            g[i][j] = ++number;
        }
    }
    while (m--)
    {
        cin >> a >> b >> r >> z;
        if (!z) // 顺时针
        {
            for (int i = a - r; i <= a + r; i++)
            {
                for (int j = b - r; j <= b + r; j++)
                {
                    f[a - b + j][a + b - i] = g[i][j];
                }
            }
            for (int i = a - r; i <= a + r; i++)
            {
                for (int j = b - r; j <= b + r; j++)
                {
                    g[i][j] = f[i][j];
                }
            }
        }
        else
        {
            for (int i = a - r; i <= a + r; i++)
            {
                for (int j = b - r; j <= b + r; j++)
                {
                    f[a + b - j][b - a + i] = g[i][j];
                }
            }
            for (int i = a - r; i <= a + r; i++)
            {
                for (int j = b - r; j <= b + r; j++)
                {
                    g[i][j] = f[i][j];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    { // 输出结果咯
        for (int j = 1; j <= n; j++)
            printf("%d ", g[i][j]);
        printf("\n");
    }

    return 0;
}