#include <iostream>
#include <algorithm>
using namespace std;
const int N = 5e6 + 10;
int a[N], dif[N];
int n, p;
int ans = 1e9;
int main()
{
    cin >> n >> p;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= p; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        dif[x] += z;
        dif[y + 1] -= z;
    }

    int x = 0;
    for (int i = 1; i <= n; i++)
    {
        x += dif[i];
        a[i] += x;
        ans = min(ans, a[i]);
    }
    cout << ans << endl;

    return 0;
}