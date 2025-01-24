#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int t, a[N], c[N], n, h;
bool check(int x, int H)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += a[i];
    }
    sum = sum * x;
    for (int i = 1; i <= n; i++)
    {
        sum -= a[i] * (ceil(x / c[i]));
    }

    if (sum >= H)
        return true;
    else
        return false;
}
int main()
{
    cin >> t;
    scanf("%d %d", &h, &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &c[i]);
    }
    while (t--)
    {
        int H = h;
        int l = 0, r = H + 1;
        while (l + 1 != r)
        {
            int mid = l + r >> 1;
            if (check(mid, H))
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }
        if (check(r, H))
        {
            cout << r;
        }
        else
        {
            cout << l;
        }
    }

    return 0;
}