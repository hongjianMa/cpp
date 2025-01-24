#include <iostream>
#define int long long
int s[100010];

void solve()
{
    int n, m, l, r;
    int x;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> x;
        s[i] = s[i - 1] + x;
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     std::cout << s[i] << " ";
    // }
    // std::cout << std::endl;
    for (int i = 1; i <= m; i++)
    {
        std::cin >> l >> r;
        std::cout << s[r] - s[l - 1] << std::endl;
    }
}

signed main()
{
    solve();

    return 0;
}