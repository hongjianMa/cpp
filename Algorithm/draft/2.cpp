#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, q, b[N];
int a[N];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, index1, index2, y, z;
        bool flag = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + 1 + n);
        for (int i = n - 1; i >= 1; i--)
        {
            if (a[i] == a[i + 1])
            {
                for (int j = 1, last = -1e9; j <= n; j++)
                {
                    if (j == i || j == i + 1)
                        continue;
                    if (a[j] - last < 2 * a[i])
                    {
                        cout << a[i] << " " << a[i] << " " << a[j] << " " << last << endl;
                        flag = 1;
                        break;
                    }
                    last = a[j];
                }
                break;
            }
        }
        if (!flag)
            cout << -1 << endl;
    }
    return 0;
}