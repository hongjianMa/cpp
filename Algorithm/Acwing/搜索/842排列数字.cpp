#include <bits/stdc++.h>
int n;
int a[10];
bool st[10];
void dfs(int x)
{
    if (x > n)
    {
        for (int i = 1; i <= n; i++)
            std::cout << a[i] << " ";
        std::cout << "\n";
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!st[i])
        {
            a[x] = i;
            st[i] = 1;
            dfs(x + 1);
            a[x] = 0;
            st[i] = 0;
        }
    }
}
int main()
{
    std::cin >> n;
    dfs(1);

    return 0;
}