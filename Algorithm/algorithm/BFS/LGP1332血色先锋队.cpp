#include <iostream>
#include <utility>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 510;
typedef pair<int, int> pii;
int n, m;
int dist[N][N];
pii q[N * N];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int hh = 0, tt = -1;

void bfs()
{

    while (hh <= tt)
    {
        auto t = q[hh++];
        for (int i = 0; i < 4; i++)
        {
            int a = t.first + dx[i];
            int b = t.second + dy[i];
            if (a < 1 || b < 1 || a > n || b > m)
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
    int a, b;

    memset(dist, -1, sizeof dist);
    cin >> n >> m >> a >> b;
    for (int i = 1; i <= a; i++)
    {
        int x, y;
        cin >> x >> y;
        q[++tt] = {x, y};
        dist[x][y] = 0;
    }
    bfs();
    for (int i = 1; i <= b; i++)
    {
        int x, y;
        cin >> x >> y;
        printf("%d\n", dist[x][y]);
    }
    return 0;
}