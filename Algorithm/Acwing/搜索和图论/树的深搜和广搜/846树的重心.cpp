#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int ne[N * 2], h[N], e[N * 2], idx;
int ans = N, n;
bool st[N * 2];
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

// 删除以u节点为根节点的
int dfs(int u)
{
    int sum = 1; // 存储 以u为根的树 的节点数, 包括u，如图中的4号节点
    int res = 0; // 存储 删掉某个节点之后，最大的连通子图节点数
    st[u] = true;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!st[j])
        {
            int s = dfs(j);
            res = max(res, s);
            sum += s;
        }
    }
    // n-sum 如图中的n-size值，不包括根节点4；
    res = max(res, n - sum); // 选择u节点为重心，最大的 连通子图节点数
    ans = min(res, ans);     // 遍历过的假设重心中，最小的最大联通子图的 节点数
    return sum;
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    dfs(1);
    cout << ans;

    return 0;
}