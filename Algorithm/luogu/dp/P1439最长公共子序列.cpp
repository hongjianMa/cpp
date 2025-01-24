#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N], b[N], f[N], myMap[N];
int main()
{
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        myMap[a[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &b[i]);
        f[i] = 0x7fffffff;
    }
    int len = 0;
    f[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (myMap[b[i]] > f[len])
            f[++len] = myMap[b[i]];
        else
        {
            int l = 0, r = len;
            while (l < r)
            {
                int mid = l + r >> 1;
                if (f[mid] > myMap[b[i]])
                    r = mid;
                else
                {
                    l = mid + 1;
                }
            }
            f[l] = min(f[l], myMap[b[i]]);
        }
    }
    printf("%d", len);

    return 0;
}