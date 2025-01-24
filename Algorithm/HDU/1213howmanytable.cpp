#include <bits/stdc++.h>
using namespace std;
const int N = 1050;

// 并查集优化
int s[N + 1];
int height[N + 1];
void init_set() // 初始化
{
    for (int i = 1; i <= N; i++)
    {
        s[i] = i;
        height[i] = 0;
    }
}

int find_set(int x) // 查找优化
{
    if(x != s[x]) s[x] = find_set(s[x]);
    return s[x];
}

void union_set(int x, int y) // 优化合并
{
    x = find_set(x);
    y = find_set(y);

    if (height[x] == height[y])
    {
        height[x] = height[x] + 1; // 合并，树的高度加一
        s[y] = x;
    }
    else
    {
        if (height[x] < height[y])  // 把矮树合并到高数上，高树的高度保持不变
        {
            s[x] = y;
        }
        else
        {
            s[y] = x;
        }
    }
}
 
int main()
{
    int t, n, m, x, y;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        init_set();
        for (int i = 1; i <= m; i++)
        {
            cin >> x >> y;
            union_set(x, y);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (i == s[i])
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}