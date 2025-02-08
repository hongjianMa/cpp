#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 150005; // 最大节点数+10的缓冲区
int n, m;             // n: 节点数, m: 边数
int dist[N];          // 存储起点到各点的最短距离
bool st[N];           // 标记节点是否已确定最短路径

typedef pair<int, int> PII;

int ne[N], h[N], e[N], w[N], idx;

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
int Dijkstra()
{
    memset(dist, 0x3f, sizeof dist); // 初始化所有距离为无穷大
    dist[1] = 0;                     // 起点到自身的距离为0
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});
    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();
        int distance = t.first, ver = t.second;
        if (st[ver])
            continue;
        st[ver] = true;
        for (int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > distance + w[i])
            {
                dist[j] = distance + w[i];
                heap.push({dist[j], j});
            }
        }
    }
    // 判断终点是否可达
    if (dist[n] == 0x3f3f3f3f)
        return -1;
    return dist[n];
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    int ans = Dijkstra();
    cout << ans << endl;
    return 0;
}