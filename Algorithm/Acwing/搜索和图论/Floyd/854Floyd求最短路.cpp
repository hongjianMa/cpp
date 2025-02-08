#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 210, INF = 1e9;
int dist[N][N];
int n, m, k;

void floyd()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        dist[x][y] = min(dist[x][y], z);
    }
    floyd();
    while (k--)
    {
        int x, y;
        cin >> x >> y;
        if (dist[x][y] > INF / 2)
            cout << "impossible" << endl;
        else
            cout << dist[x][y] << endl;
    }
    return 0;
}