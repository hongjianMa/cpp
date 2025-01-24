#include <iostream>

using namespace std;
const int N = 1e3 + 10;
int n, m, q;
int s[N][N];
void solve()
{
    cin >> n >> m >> q;
    int x11, x22, y11, y22;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int x;
            cin >> x;
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + x;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << s[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 1; i <= q; i++)
    {

        cin >> x11 >> y11 >> x22 >> y22;
        cout << s[x22][y22] - s[x11 -1][y22] - s[x22][y11-1] + s[x11-1][y11-1] << endl;
    }
}

int main()
{
    solve();

    return 0;
}