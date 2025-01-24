#include <iostream>
#include <algorithm>
using namespace std;
const int N = 3e4 + 4;
int a[N], maxprice, n, cnt = 0;
int main()
{
    cin >> maxprice >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    // for(int i = 1;i<=n;i++)
    // {
    //     cout<<a[i]<<" ";
    // }
    for (int i = 1, j = n; i <= j; i++)
    {
        while (a[j] + a[i] > maxprice)
        {
            cnt++;
            j--;
        }
        if (a[i] + a[j] <= maxprice)
        {
            cnt++;
            j--;
        }
        else if (i == j)
            cnt++;
    }

    cout << cnt;

    return 0;
}