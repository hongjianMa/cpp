#include <bits/stdc++.h>
char g[21][21];
int n;
bool col[20], dg[20], udg[20];
void dfs(int x)
{
    if (x == n)
    {
        for (int i = 0; i < n; i++)
            puts(g[i]);
        puts("");
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!col[i] && !dg[i + x] && !udg[i - x + n])
        {
            col[i] = dg[i + x] = udg[i - x + n] = 1;
            g[x][i] = 'Q';
            dfs(x + 1);
            col[i] = dg[i + x] = udg[i - x + n] = 0;
            g[x][i] = '.';
        }
    }
}
int main()
{
    std::cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g[i][j] = '.';
    dfs(0);
    return 0;
}