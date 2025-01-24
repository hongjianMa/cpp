#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 210;
int a, b, arr[N], dis[N], n;
int res = 1e9;
void dfs(int x, int sum)
{
    //一遍走到终点才不会超时

    dis[x] = sum;  
    if (x < 0 || x > n)
        return;

    if (x == b)
    {
        res = min(res, sum);
        return;
    }

    if (sum >= res)
        return;

    // 上楼
    if (x + arr[x] <= n && sum + 1 < dis[x + arr[x]])
    {
        dfs(x + arr[x], sum + 1);
    }

    // 下楼
    if (x - arr[x] > 0 && sum + 1 < dis[x - arr[x]])
    {

        dfs(x - arr[x], sum + 1);
    }
}

int main()
{
    memset(dis, 0x3f, sizeof(dis));
    scanf("%d %d %d", &n, &a, &b);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    dfs(a, 0);
    if (res == 1e9)
    {
        printf("-1");
    }
    else
    {
        printf("%d", res);
    }
    return 0;
}