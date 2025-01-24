#include <iostream>
#include <cmath>
using namespace std;
const int N = 25;
int n, k, ans = 0;
bool isPrime(int x)
{
    int sq = sqrt(x);
    for (int i = 2; i <= sq; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}
void dfs(int x, int start, int *a, int *b)
{

    if (x > k)
    {
        if (isPrime(b[1] + b[2] + b[3]))
            ans++;
        return;
    }

    for (int i = start; i <= n; i++)
    {
        b[x] = a[i];
        dfs(x + 1, i + 1, a, b);
        b[x] = 0;
    }
}

signed main()
{
    cin >> n >> k;
    int *a = new int[n + 1];
    int *b = new int[n + 1];
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    dfs(1, 1, a, b);
    cout << ans;

    return 0;
}