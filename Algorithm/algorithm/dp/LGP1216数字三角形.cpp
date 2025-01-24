#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e3 + 10;

int n;
int g[N][N];
// int f[N][N];
// 把二维优化为一维数组
int f[N];
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
    // for(int i = n;i>=1;i--)
    // {
    //     for(int j = 1;j<=i;j++)
    //     {
    //         f[i][j] = max(f[i+1][j], f[i+1][j+1]) + g[i][j];
    //     }
    // }
    // cout<<f[1][1];
    for(int i = n;i>=1;i--)
    {
        for(int j = 1;j<=i;j++)
        {
            f[j] = max(f[j], f[j+1]) + g[i][j];
        }
    }
    cout<<f[1];

    return 0;
}