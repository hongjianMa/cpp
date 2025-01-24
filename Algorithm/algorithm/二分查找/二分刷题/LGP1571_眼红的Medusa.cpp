#include <iostream>
#include <algorithm>
using namespace std;
#define int long long 
const int N = 100010;
int n, m;
int a[N], b[N];
bool biserch(const int &x)
{
    int l = 0, r = m + 1;
    while (l + 1 != r)
    {
        int mid = l + r >> 1;
        if (b[mid] < x)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    if (b[r] == x)
        return true;
    else
        return false;
}
signed main()
{
    scanf("%ld %ld", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%ld", &a[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%ld", &b[i]);
    }
    sort(b, b + m + 1);
    for (int i = 1; i <= n; i++)
    {

        if (biserch(a[i]))
        {
            printf("%ld ", a[i]);
        }
    }

    return 0;
}
