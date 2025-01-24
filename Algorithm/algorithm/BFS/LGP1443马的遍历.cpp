#include <iostream>
#include <utility>
#include <cstring>
using namespace std;
const int N = 410;
typedef pair<int, int> pii;
int n, m, x0, y2, res = 0;
int dist[N][N];
pii q[N * N];
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
void bfs(int x, int y)
{
    memset(dist, -1, sizeof dist);
    q[0] = {x, y};
    int hh = 0, tt = 0;
    dist[x][y] = 0;
    while (hh <= tt)
    {

        auto t = q[hh++];
        for (int i = 0; i < 8; i++)
        {
            int a = t.first + dx[i];
            int b = t.second + dy[i];
            if (a < 0 || b < 0 || a >= n || b >= m)
                continue;
            if (dist[a][b] >= 0)
                continue;
            dist[a][b] = dist[t.first][t.second] + 1;
            q[++tt] = {a, b};
        }
    }
}

signed main()
{
    cin >> n >> m >> x0 >> y2;
    bfs(x0 - 1, y2 - 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d    ", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}