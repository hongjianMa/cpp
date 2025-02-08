#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10;
int n, m, p;
int fa[N];
vector<int> siz(N, 1);

void init()
{
    for (int i = 1; i <= n; i++)
        fa[i] = i;
}

int find(int x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]); // 带有路径压缩的查找
}

void unionset(int x, int y)
{
    x = find(x), y = find(y);
    if (x == y)
        return;
    if (siz[x] > siz[y]) // 小集合合并到大集合中
        swap(x, y);
    fa[x] = y;
    siz[y] += siz[x];
}

int main()
{
    cin >> n >> m >> p;

    // 初始化
    init();
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        unionset(x, y);
    }
    for (int i = 1; i <= p; i++)
    {
        int x, y;
        cin >> x >> y;
        if (find(fa[x]) == find(fa[y]))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}