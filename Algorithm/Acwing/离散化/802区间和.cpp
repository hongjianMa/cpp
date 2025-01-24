// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

using namespace std;
typedef pair<int, int> PII;
const int N = 3e5 + 10;  // 坐标 x数量是1e5， l, r也是1e5
                         // 三者加起来就是3e5                   
int n, m;
int s[N], a[N];
vector<PII> add, query;  // 存插入和查询
vector<int> alls;

int find(int x)
{
    int l = 0, r = alls.size() - 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (alls[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    return r + 1; // 这里+1是为了s[i - 1]不越界
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int x, c;
        cin >> x >> c;
        alls.push_back(x);
        add.push_back({x, c});
    }

    for (int i = 1; i <= m; i++)
    {
        int l, r;
        cin >> l >> r;
        alls.push_back(l);
        alls.push_back(r);
        query.push_back({l, r});
    }

    // 离散化
    // 1.去重
    sort(alls.begin(), alls.end());  // 排序为了unique函数去重
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    // 2.离散缩小
    // 处理插入
    for (auto item : add)
    {
        int x = find(item.first);
        a[x] += item.second;
    }

    // 预处理前缀和
    for (int i = 1; i <= alls.size(); i++)
    {
        s[i] = s[i - 1] + a[i];
    }

    // 处理询问
    for (auto item : query)
    {
        int l = find(item.first);
        int r = find(item.second);
        cout << s[r] - s[l - 1] << endl;
    }

    return 0;
}