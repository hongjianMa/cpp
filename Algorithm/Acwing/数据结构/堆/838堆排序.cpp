#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int a[N], n, m;
int r; // r:模拟堆数组的右边界

void down(int u)
{
    int t = u;

    // 有左儿子，并且左儿子比t节点的值小，更新t
    if (2 * u <= r && a[2 * u] < a[t])
        t = 2 * u;

    // 有右儿子，并且右儿子比t节点的值小，更新t
    if (2 * u + 1 <= r && a[2 * u + 1] < a[t])
        t = 2 * u + 1;

    // 如果待调整点不是最小的
    if (u != t)
    {
        swap(a[u], a[t]);
        down(t);
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    // 从第一个非叶节点开始，从右到左，从下到上处理每个节点
    r = n;
    for (int i = n / 2; i >= 1; i--)
    {
        down(i);
    }
    // 输出m个最小值
    for (int i = 1; i <= m; i++)
    {
        cout << a[1] << " ";
        swap(a[1], a[r]);
        r--;
        down(1);
    }
    return 0;
}