#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N], b[N];

void solve()
{
    int x, cnta = 0, cntb = 0;
    while (scanf("%d", &x) != -1) // 最长下降子序列长度 == 构成的上升子序列的序列个数
    {
        // 处理上升子序列（拦截导弹的数量）
        int l = 0, r = cnta; // 修改边界
        while (l < r)
        {
            int m = (l + r) / 2;
            if (x > a[m])
            {
                r = m; // 找到第一个小于等于 x 的位置
            }
            else
            {
                l = m + 1; // 找到第一个大于 x 的位置
            }
        }
        if (l < cnta)
        {
            a[l] = x; // 更新
        }
        else
        {
            a[cnta++] = x; // 新增
        }

        // 处理下降子序列（最少系统数量）
        l = 0, r = cntb; // 修改边界
        while (l < r)    //  构成的下降子序列的序列个数 == 最长上升子序列长度
        {
            int m = (l + r) / 2;
            if (x <= b[m])
            {
                r = m; // 找到第一个大于 x 的位置
            }
            else
            {
                l = m + 1; // 找到第一个小于等于 x 的位置
            }
        }
        if (l < cntb)
        {
            b[l] = x; // 更新
        }
        else
        {
            b[cntb++] = x; // 新增
        }
    }
    printf("%d\n%d\n", cnta, cntb); // 输出拦截数量和系统数量
}

int main()
{
    solve();
    return 0;
}
