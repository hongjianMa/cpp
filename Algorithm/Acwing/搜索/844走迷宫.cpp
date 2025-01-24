#include <bits/stdc++.h>
// using namespace std;
typedef std::pair<int, int> PII;
const int N = 110;
PII q[N * N];
int hh, tt = -1, n, m, st[N][N];
char g[N][N];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void bfs(int x, int y)
{
    memset(st, -1, sizeof st);
    q[++tt] = {x, y};
    st[x][y] = 0;
    while (hh <= tt)
    {
        auto t = q[hh++];
        for (int i = 0; i < 4; i++)
        {
            int a = t.first + dx[i];
            int b = t.second + dy[i];
            if (g[a][b] == '1' || st[a][b] >= 0)
                continue;
            if (a < 1 || b < 1 || a > n || b > m)
                continue;
            st[a][b] = st[t.first][t.second] + 1;
            q[++tt] = {a, b};
        }
    }
}

int main()
{
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            std::cin >> g[i][j];
        }
    }
    bfs(1, 1);
    std::cout << st[n][m];
    return 0;
}