#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 5e2 + 10; // 最大节点数+10的缓冲区
int n, m;               // n: 节点数, m: 边数
int g[N][N];            // 邻接矩阵存储图结构（处理稠密图）
int dist[N];            // 存储起点到各点的最短距离
bool st[N];             // 标记节点是否已确定最短路径

int Dijkstra()
{
    memset(dist, 0x3f, sizeof dist); // 初始化所有距离为无穷大
    dist[1] = 0;                     // 起点到自身的距离为0

    // 进行n次迭代，每次确定一个节点的最短路径
    for (int i = 1; i <= n; i++)
    {
        int t = -1;
        // 找出当前未确定最短路径的节点中距离最小的
        for (int j = 1; j <= n; j++)
        {
            if (!st[j] && (t == -1 || dist[j] < dist[t]))
                t = j;
        }

        st[t] = true; // 标记该节点已确定最短路径

        // 通过当前节点t更新其他节点的距离
        for (int j = 1; j <= n; j++)
        {
            // 松弛操作：尝试用 dist[t] + g[t][j] 更新 dist[j]
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
    }

    // 判断终点是否可达
    if (dist[n] == 0x3f3f3f3f)
        return -1;
    return dist[n];
}

int main()
{
    cin >> n >> m;
    memset(g, 0x3f, sizeof g); // 初始化邻接矩阵为无穷大

    // 处理输入边，注意处理重边保留最小值
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        g[x][y] = min(g[x][y], z); // 对于重边，只保留最短的边
    }

    int ans = Dijkstra();
    cout << ans << endl;

    return 0;
}