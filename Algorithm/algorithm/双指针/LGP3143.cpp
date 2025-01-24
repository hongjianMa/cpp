#include <iostream>
#include <algorithm>
using namespace std;
const int N = 5e4 + 10;
int n, k, ans = 0;
int a[N], cnt_1[N], cnt_2[N];
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1, j = 1; i <= n; i++)
    {
        while (j <= i && a[i] - a[j] > k)
        {
            j++;
        }
        cnt_1[i] = max(cnt_1[i - 1], i - j + 1);
    }
    for (int i = n, j = n; i >= 1; i--)
    {
        while (j >= i && a[j] - a[i] > k)
        {
            j--;
        }
        cnt_2[i] = max(cnt_2[i + 1], j - i + 1);
    }

    for (int i = 1; i <= n - 1; i++)
    {
        ans = max(ans, cnt_1[i] + cnt_2[i + 1]);
    }
    cout << ans;

    return 0;
}