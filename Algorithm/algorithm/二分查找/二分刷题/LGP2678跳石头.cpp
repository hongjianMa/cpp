#include <iostream>

using namespace std;
const int N = 5e5 + 10;
int L, n, m, a[N];

bool check(int x)
{
    int i = 0, now = 0, cnt = 0;
    while (i < n + 1)
    {
        i++;
        while (a[i] - a[now] < x)
        {
            cnt++;
            if (i < n + 1)
            {
                i++;
            }
            else
            {
                if (cnt <= m)
                    return true;
                else
                    return false;
            }
        }
        now = i;
    }
    if (cnt <= m)
        return true;
    else
        return false;
}
signed main()
{
    scanf("%d%d%d", &L, &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    a[n + 1] = L;//把最后终点也加进去
    int l = 0, r = L + 1;
    while (l + 1 != r)
    {
        int mid = l + r >> 1;
        if (check(mid))
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    if (check(l))
    {
        cout << l;
    }
    else 
    {
        cout<<r;
    }

    return 0;
}