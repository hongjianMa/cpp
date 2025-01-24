#include <bits/stdc++.h>
using namespace std;
struct node
{
    int id, v, s, f;
} a[32005];
int dp[32005], b[32005];

bool cmp(node a, node b)
{
    if (a.id == b.id)
        return a.f < b.f;
    return a.id < b.id;
}

void solve()
{
    int n, m, q, v, w;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> v >> w >> q;
        if (q == 0)
        {
            a[i].id = i, a[i].v = v, a[i].s = v * w, a[i].f = 0;
        }
        else
        {
            a[i].id = q, a[i].v = v, a[i].s = v * w, a[i].f = ++b[q];
        }
    }
    sort(a + 1, a + 1 + m, cmp);

    for (int i = 1; i <= m; i++)
    {
        if (a[i].f)
            continue;
        for (int j = n; j >= a[i].v; j--)
        {

            dp[j] = max(dp[j], dp[j - a[i].v] + a[i].s); // 只有一个主件的时候
            // cout<<dp[j]<<" ";
            if (a[i].id == a[i + 1].id && j >= a[i].v + a[i + 1].v)  // 考虑选择附件1
                dp[j] = max(dp[j], dp[j - a[i].v - a[i + 1].v] + a[i].s + a[i + 1].s);
            if (a[i].id == a[i + 2].id && j >= a[i].v + a[i + 2].v)  // 考虑选择附件2
                dp[j] = max(dp[j], dp[j - a[i].v - a[i + 2].v] + a[i].s + a[i + 2].s);
            if (a[i].id == a[i + 2].id && j >= a[i].v + a[i + 1].v + a[i + 2].v)  // 考虑两个附件都选择
                dp[j] = max(dp[j], dp[j - a[i].v - a[i + 1].v - a[i + 2].v] + a[i].s + a[i + 1].s + a[i + 2].s);
        }
    }
    // cout<<endl;
    cout << dp[n] << endl;
    // for(int i = 1;i<=m;i++)
    // {
    //     cout<<a[i].id<<" "<<a[i].v<<" "<<a[i].s<<endl;
    // }
}

int main()
{
    solve();
    return 0;
}