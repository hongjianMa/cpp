#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f;
int n, m;
int dist[N], cnt[N];
bool st[N];

// 领接表
int ne[N], e[N], h[N], w[N], idx;
void add(int a, int b, int c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

bool spfa()
{
    // 超级初始化，先把每一个节点入队
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        st[i] = 1;
        q.push(i);
    }

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
                cnt[v] = cnt[u] + 1;
                if (cnt[v] >= n)
                    return true;
                // 如果队列中已存在v，则不需要将v重复插入,优化一下
                if (!st[v])
                {
                    q.push(v);
                    st[v] = 1;
                }
            }
        }
    }
    return false;
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
    bool ans = spfa();
    if (ans)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}