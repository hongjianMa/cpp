#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f;
int n, m;
int dist[N];
bool st[N];

// 领接表
int ne[N], e[N], h[N], w[N], idx;
void add(int a, int b, int c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

int spfa()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    queue<int> q;
    q.push(1);
    st[1] = 1;
    while (q.size())
    {
        auto u = q.front();
        q.pop();
        st[u] = 0;
        for (int i = h[u]; i != -1; i = ne[i])
        {
            int v = e[i];
            if (dist[v] > dist[u] + w[i])
            {
                dist[v] = dist[u] + w[i];
                // 如果队列中已存在v，则不需要将v重复插入,优化一下
                if (!st[v])
                {
                    q.push(v);
                    st[v] = 1;
                }
            }
        }
    }
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
    int ans = spfa();
    if (dist[n] == INF)
        cout << "impossible";
    else
        cout << dist[n];

    return 0;
}