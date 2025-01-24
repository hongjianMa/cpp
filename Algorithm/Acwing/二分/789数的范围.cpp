#include <bits/stdc++.h>
const int N = 1e5 + 10;
int n, q;
int a[N], b[N];
int lfind(int x)
{
    int l = 0, r = n;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (a[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    if (a[l] == x)
        return l - 1;
    else
        return -1;
}

int rfind(int x)
{
    int l = 0, r = n;
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (a[mid] <= x)
            l = mid;
        else
            r = mid - 1;
    }
    if (a[l] == x)
        return l - 1;
    else
        return -1;
}

int main()
{
    std::cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }
    int x;
    for (int i = 1; i <= q; i++)
    {
        std::cin >> x;
        std::cout << lfind(x) << " " << rfind(x) << std::endl;
    }

    return 0;
}