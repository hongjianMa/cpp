#include <bits/stdc++.h>
using namespace std;

const int MOD = 80112002;    // 取模值
const int N = 5e3 + 10;      // 最大生物种类数
const int M = 5e5 + 10;      // 最大关系数
int n, m;                    // 生物种类数、关系数
int64_t ans;                 // 最终答案
int ne[M], h[N], e[M], idx;  // 邻接表存图（生产者→消费者）
int q[M], d[N], tt = -1, hh; // 队列、入度数组
int out[N];                  // 出度数组（用于判断顶级消费者）
int num[N];                  // 到每个节点的路径数（动态规划数组）

// 添加有向边 a→b 表示a被b吃
void add(int a, int b)
{
    e[idx] = b;     // 目标节点
    ne[idx] = h[a]; // 插入链表头部
    h[a] = idx++;   // 更新头指针
}

void bfs()
{
    // 初始化：将所有入度为0的生产者加入队列
    for (int i = 1; i <= n; i++)
    {
        if (d[i] == 0)
        {
            q[++tt] = i; // 加入队列
            num[i] = 1;  // 起始点路径数为1
        }
    }

    // 拓扑排序处理所有节点
    while (tt >= hh)
    {
        int a = q[hh++]; // 取出队首节点

        // 遍历所有吃a的生物（a的后继节点）
        for (int i = h[a]; i != -1; i = ne[i])
        {
            int b = e[i];
            d[b]--;                           // 后继节点入度减1
            num[b] = (num[b] + num[a]) % MOD; // 累加路径数

            // 当入度为0时加入队列（确保拓扑顺序）
            if (d[b] == 0)
            {
                q[++tt] = b;
            }
        }
    }

    // 统计所有出度为0的顶级消费者的路径数
    for (int i = 1; i <= n; i++)
    {
        if (!out[i]) // 没有后继节点
            ans = (ans + num[i]) % MOD;
    }
}

int main()
{
    memset(h, -1, sizeof h); // 初始化邻接表

    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b); // 构建a→b的有向边
        d[b]++;    // b的入度增加（被吃的生物作为箭头终点）
        out[a]++;  // a的出度增加（吃别人的生物作为箭头起点）
    }

    bfs(); // 执行拓扑排序+动态规划计算

    cout << ans;
    return 0;
}