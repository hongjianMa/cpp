#include <iostream>
#include <utility>
#include <cstring>
#include <queue>
using namespace std;
const int N = 1e3 + 10;
typedef pair<int, int> pii; // 数对

int n, x1, y11, x2, y2; // y1与头文件包含冲突，用y11
char g[N][N];           // 存地图
int dist[N][N];         // 记录答案

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int bfs(int x, int y)
{
    memset(dist, 0, sizeof dist); // 初始化，可有可无
    queue<pii> q;                 // 建队列
    q.push({x, y});
    while (!q.empty())
    {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {

            int a = t.first + dx[i];
            int b = t.second + dy[i];

            // 过滤不符合条件（边界）
            if (a < 0 || b < 0 || a >= n || b >= n)
                continue;
            if (g[a][b] == '1')
                continue;
            if (dist[a][b])
                continue;
            dist[a][b] = dist[t.first][t.second] + 1; // 更新答案
            q.push({a, b});
            if (dist[x2 - 1][y2 - 1]) // 走到了目的地就返回答案
                return dist[x2 - 1][y2 - 1];
        }
    }
    return -1;
}

signed main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> g[i];
    }
    cin >> x1 >> y11 >> x2 >> y2;
    int res = bfs(x1 - 1, y11 - 1);
    cout << res;
    return 0;
}