#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int L, n, k, a[N],s[N];
bool check(int x)
{
    int cnt = 0;
    for(int i = 1;i<=n+1;i++)
    {
        if(s[i]>x)
        {
            cnt++;
            int y = s[i] - x;
            while(y>x)
            {
                y -= x;
                cnt++;
            }
        }
    }
    if(cnt<=k) return true;
    else return false;
}
int main()
{
    cin >> L >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    a[n + 1] = L;
    sort(a, a + n + 1);
    for(int i = 1;i<=n+1;i++)
    {
        s[i] = a[i] - a[i-1];
    }
    int l = 0, r = L + 1;
    while (l + 1 < r)
    {
        int mid = l + r >> 1;
        if (check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    if(check(r))
    {
        cout<<r;
    }
    else
    {
        cout<<l;
    }

    return 0;
}