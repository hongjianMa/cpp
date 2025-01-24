#include <iostream>
using namespace std;
const int N = 25;
int n, m, res = 0;
char g[N][N];
bool st[N][N];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int a = x + dx[i];
        int b = y + dy[i];
        if (g[a][b] == '#')
            continue;
        if (a < 1 || a > m || b < 0 || b >= n)
            continue;
        if (st[a][b])
            continue;

        st[a][b] = true;
        res++;
        dfs(a, b);
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        scanf("%s", &g[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (g[i][j] == '@')
            {
                st[i][j] = true;
                dfs(i, j);
            }
        }
    }
    res++;
    cout << res;

    return 0;
}