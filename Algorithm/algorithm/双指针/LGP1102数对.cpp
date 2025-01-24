#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

const int N = 2e5 + 10;
int n, c;
int a[N];
signed main()
{
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
    }
    int cnt = 0;
    sort(a+1, a + n + 1);
    for (int i = 1, j = 1, k = 1; i <= n; i++)
    {
        while (a[i] - a[j] >= c && i >= j)
        {
            j++;
        }
        while (a[i] - a[k] > c && i >= k)
        {
            k++;
        }
        cnt += j - k;
    }
    cout << cnt;
    return 0;
}