#include <iostream>

using namespace std;
const int N = 30;
int a[N];
int n, r;

void dfs(int x, int start)
{
    if (x > r)
    {
        for (int i = 1; i <= r; i++)
        {
            printf("%3d", a[i]);
        }
        printf("\n");
        return ;//很关键
    }
    for (int i = start; i <= n; i++)
    {
        a[x] = i;
        dfs(x + 1, i + 1);
        a[x] = 0;
    }
}

signed main()
{
    cin >> n >> r;
    dfs(1, 1);
    return 0;
}