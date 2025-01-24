#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int MOD = 1e9 + 7;
int a[N], num[N];
int n, maxa, ans;

int C(int x, int k)
{
    return (k == 1 ? x : x * (x - 1) / 2) % MOD;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        num[a[i]]++;
        maxa = max(maxa, a[i]);
    }

    for (int i = 2; i <= maxa; i++)
    {
        if (num[i] >= 2)
        {
            int times = C(num[i], 2) % MOD;
            for (int j = 1; j <= i / 2; ++j)
            {                                                     // 枚举被合成的边(到i / 2即可)
                if (j != i - j && num[j] >= 1 && num[i - j] >= 1) // 用来合成的木棒长度不等
                    ans += times * C(num[j], 1) * C(num[i - j], 1) % MOD;
                if (j == i - j && num[j] >= 2) // 用来合成的木棒长度相等
                    ans += times * C(num[j], 2) % MOD;
                ans %= MOD;
            }
        }
    }
    cout << ans;

    return 0;
}