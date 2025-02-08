#include <iostream>
#include <cstring>

using namespace std;
const int N = 1e5 + 10;
int ne[N], h[N], e[N], idx; // 数组模拟邻接表
int n, m, d[N];             // d[N]记录入度数量，
int q[N], hh, tt = -1;      // 数组模拟队列

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void bfs()
{
    // 先处理入度为0的节点，将它入队
    for (int i = 1; i <= n; i ++ )
    {
        if(d[i] == 0)
        {
            q[++tt] = i;
        }
    }

    while (hh <= tt)
    {
        int t = q[hh++];
        for (int i = h[t]; i != -1; i = ne[i])  // 临界点遍历模板
        {
            int b = e[i];  // 获取节点b
            d[b] --; // 入度-1
            if (d[b] == 0)
                q[++tt] = b;
        }
    }
    if (tt == n-1) // 如果可以用拓扑排序，则队列中的数量和图的顶点数是相同的
    {
        for(int i = 0; i < n; i ++ )
        {
            cout << q[i] << " "; // 队列中保存了所有入度为0的点，依次输出
        }
    }
    else cout << -1;
}


int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);  // 初始化所有头结点，非常重要
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
        d[b]++; // b节点的入度+1
    }
    bfs();


    return 0;
}