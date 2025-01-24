#include <bits/stdc++.h>
using namespace std;
const int N = 100;
// int g[N][N];
bool st[N][N];
int n, m, t, sx, sy, fx, fy;
int ans = 0;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
void dfs(int x, int y)
{
    if (x == fx && y == fy)
    {
        ans++;
        return;
    }
    if (x > n || x < 1 || y > m || y < 1)
        return;
    
    st[x][y] = 1;

    for(int i = 0;i<4;i++)
    {
        int a = x + dx[i];
        int b = y + dy[i];
        if(st[a][b]) continue;
        if(a<1||b<1||a>n||b>m) continue;
        dfs(a,b);   
    }
    st[x][y] = 0;
}

int main()
{
    cin >> n >> m >> t;
    cin >> sx >> sy >> fx >> fy;
    for (int i = 1; i <= t; i++)
    {
        int x, y;
        cin >> x >> y;
        st[x][y] = 1;
    }
    dfs(sx, sy);
    cout << ans << endl;
    return 0;
}