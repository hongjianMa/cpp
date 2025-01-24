#include <iostream>
using namespace std;
const int N = 2e5 + 10;
long long n, s[N], a[N];
long long ans = 0;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
    {
        s[i] = s[i - 1] + a[i];
    }
    for (int i = 1; i < n; i++)
    {
        ans += a[i] * (s[n] - s[i]);
    }
    cout << ans << endl;

    return 0;
}