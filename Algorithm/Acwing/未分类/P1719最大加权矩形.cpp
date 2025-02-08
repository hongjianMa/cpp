#include <iostream>
using namespace std;
const int N = 122;
int n, a[N][N], s[N][N];
int func(int x1, int y11, int x2, int y22)
{
    return s[x2][y22] + s[x1 - 1][y11 - 1] - s[x2][y11 - 1] - s[x1 - 1][y22];
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }
    int ans = -1e9;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = i; k <= n; k++)
                for (int m = j; m <= n; m++)
                    ans = max(ans, func(i, j, k, m));

    cout << ans << endl;
    return 0;
}