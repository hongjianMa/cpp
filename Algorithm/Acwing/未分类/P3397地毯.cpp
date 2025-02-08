#include <iostream>
using namespace std;
const int N = 1010;
int a[N][N], n, m, x1, y_1, x2, y_2;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> x1 >> y_1 >> x2 >> y_2;
        a[x1][y_1]++;
        a[x1][y_2 + 1]--;
        a[x2 + 1][y_1]--;
        a[x2 + 1][y_2 + 1]++;
    }
    for (int i = 1; i <= n; i++, cout << "\n")
        for (int j = 1; j <= n; j++)
        {
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
            cout << a[i][j] << " ";
        }

    return 0;
}