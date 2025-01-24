// 洛谷P1020 [NOIP1999 提高组] 导弹拦截
// 动态规划 / 二分
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N], b[N];
int cnta = 0, cntb = 0;

int main()
{
    int x;
    while (cin >> x)
    {
        int l = 0, r = cnta;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (x > a[mid])
                r = mid;
            else
                l = mid + 1;
        }
        if (l < cnta)
            a[l] = x;
        else
            a[cnta++] = x;
        l = 0, r = cntb;
        while (l < r)
        {
            int mid = l + r >> 1;
            if(x<=b[mid])r = mid;
            else l = mid +1;
        }
        if(l<cntb) b[l] = x;
        else b[cntb++] = x;
    }
    cout<<cnta<<"\n"<<cntb;

    return 0;
}