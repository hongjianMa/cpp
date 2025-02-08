#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> d;
string q[1000000];
int hh, tt = -1;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int bfs(string s)
{
    string end = "123804765";
    q[++tt] = s;
    while (hh <= tt)
    {
        auto s = q[hh++];
        if (s == end)
            return d[s];
        int k = s.find('0');
         int x = k / 3, y = k % 3;
        for (int i = 0; i < 4; i++)
        {
            int a = x + dx[i];
            int b = y + dy[i];
            if (a < 0 || b < 0 || a > 2 || b > 2)
                continue;
            int dis = d[s];
            swap(s[k], s[a * 3 + b]);
            if (!d.count(s))
            {
                d[s] = dis + 1;
                q[++tt] = s;
            }
            swap(s[k], s[a * 3 + b]); // 恢复现场
        }
    }
    return -1;
}

int main()
{
    string s;
    cin >> s;
    int ans = bfs(s);
    cout << ans;

    return 0;
}