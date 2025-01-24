#include <iostream>
#include <algorithm>

using namespace std;
const int N = 2e7; // N * V * 12 ~ 1e7
int v[N], w[N];
int f[N]; // 一维优化的0-1背包

int main()
{
    int n, m;
    cin >> n >> m;
    int cnt = 0; // 用于记录实际生成的物品组的数量
    for (int i = 1; i <= n; i++)
    {
        int a, b, s; // 输入第 i 种物品的体积 a，价值 b，数量 s
        cin >> a >> b >> s;
        int k = 1;
        // 使用二进制优化分组，将 s 个物品分成若干组
        while (k <= s)
        {
            cnt++;          // 生成新的一组物品
            v[cnt] = k * a; // 当前组物品的总体积
            w[cnt] = k * b; // 当前组物品的总价值
            s -= k;         // 剩余的物品数量减去当前组的数量
            k *= 2;         // 当前组的物品数量翻倍
        }
        // 最后一组
        if (s > 0)
        {
            cnt++;
            v[cnt] = a * s;
            w[cnt] = b * s;
        }
    }
    n = cnt;
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= v[i]; j--)
        {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    cout << f[m] << endl;
    return 0;
}