#include <iostream>

using namespace std;
const int N = 1e4 + 10;
int a[N], b[N]; // a[N]记录初始外星人状态
int n, k, res = 0;
bool st[N];

void dfs(int x)
{
    if (x > n)
    {
        res++;
        if (res == k + 1)  // 表示加了k之后
        {
            for (int i = 1; i <= n; i++)
            {
                printf("%d ", b[i]);
            }
            exit(1);  // 直接退出避免超时
        }
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!res)
        {
            i = a[x];
        }
        if (!st[i])
        {
            st[i] = true;
            b[x] = i;
            dfs(x + 1);
            b[x] = 0;
            st[i] = false;
        }
    }
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    dfs(1);
    return 0;
}