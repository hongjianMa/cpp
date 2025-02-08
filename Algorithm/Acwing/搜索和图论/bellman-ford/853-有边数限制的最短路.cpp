#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
const int INF = 0x3f3f3f3f;
int n, m, k;
int dist[N]; // 最短距离
int backup[N];  // 拷贝一下dist数组

// 邻接表存图
int ne[N], h[N], e[N], w[N], idx;

void add(int a, int b, int c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

int bellman_ford()
{
    memset(dist, INF, sizeof dist);
    dist[1] = 0;
    while (k--)
    {
        memcpy(backup, dist, sizeof dist); // 每次更新前用上次的结果
        for (int i = 1; i <= n; i++)       // 执行n次松弛操作
            for (int j = h[i]; j != -1; j = ne[j])
            {
                int v = e[j];
                dist[v] = min(dist[v], backup[i] + w[j]);
            }
    }
    if (dist[n] > INF / 2) // 是因为有负权边的问题，所以dist[n]可能被更新
        return INF;
    return dist[n];
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
    }
    int ans = bellman_ford();
    if (ans == INF)
        puts("impossible");
    else
        cout << ans << endl;
    return 0;
}