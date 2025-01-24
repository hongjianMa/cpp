// //记忆化搜索

// #include <iostream>

// using namespace std;
// const int N = 1e3 + 10;
// int np, vp;
// int v[N], w[N];
// int mem[N][N];
// int dfs(int x, int sp)
// {
//     if (x > np)
//         return 0;
//     if (mem[x][sp])
//         return mem[x][sp];
//     int sum = 0;
//     if (v[x] > sp)
//         sum = dfs(x + 1, sp);
//     else
//         sum = max(dfs(x + 1, sp), dfs(x + 1, sp - v[x]) + w[x]);
//     mem[x][sp] = sum;
//     return sum;
// }

// int main()
// {
//     cin >> np >> vp;
//     for (int i = 1; i <= np; i++)
//     {
//         cin >> v[i] >> w[i];
//     }
//     int res = dfs(1, vp);
//     cout << res;

//     return 0;
// }

#include <iostream>
using namespace std;
const int N = 1e3 + 10;
int n, Sp;
int v[N], w[N];
int f[N][N];
int main()
{
    cin >> n >> Sp;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i] >> w[i];
    }
    for (int i = n; i >= 1; i--)
    {
        for (int j = 0; j <= Sp; j++)
        {
            if (j < v[i])
                f[i][j] = f[i + 1][j];
            else
            {
                f[i][j] = max(f[i + 1][j], f[i + 1][j - v[i]] + w[i]);
            }
        }
    }
    cout << f[1][Sp];

    return 0;
}