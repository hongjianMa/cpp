#include <iostream>
using namespace std;
const int N = 210;
int n, k, res = 0;
int arr[N];
void dfs(int x, int start, int cnt)
{
    if (x > k)
    {
        if (cnt == n)
        {
            res++;
        }
        return;
    }
    // 这里的剪枝很关键，就是剩下的位置乘以i就是后面最小的情况
    // 最小的情况都不满足，直接就剪掉
    for (int i = start; ((k - x + 1) * i + cnt) <= n; i++)
    {
        arr[x] = i;
        dfs(x + 1, i, cnt + i);
        arr[x] = 0;
    }
}
int main()
{
    cin >> n >> k;
    dfs(1, 1, 0);
    cout << res;
    return 0;
}