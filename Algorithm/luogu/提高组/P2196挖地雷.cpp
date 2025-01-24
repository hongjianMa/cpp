#include <bits/stdc++.h>

using namespace std;
int g[22][22], a[22], b[22], path[22];
int n, ans = -1, cnt = 0;
bool st[22];

bool check(int x)
{
    for (int i = 1; i <= n; i++)
    {
        if (!st[i] && g[x][i])
            return false;
    }
    return true;
}

void dfs(int x, int sum, int step)
{
    if (check(x))
    {
        if (ans < sum)
        {
            ans = sum;
            cnt = step;
            for (int i = 1; i <= step; i++)
            {
                path[i] = b[i];
            }
        }
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (g[x][i] && !st[i])
        {
            st[i] = 1;
            b[step + 1] = i;
            dfs(i, sum + a[i], step + 1);
            st[i] = 0;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int x;
            cin >> x;
            if (x)
            {
                g[i][j] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        st[i] = 1;
        b[1] = i;
        dfs(i, a[i], 1);
        st[i] = 0;
    }
    for (int i = 1; i <= cnt; i++)
    {
        cout << path[i] << " ";
    }
    cout << endl;
    cout << ans;

    return 0;
}