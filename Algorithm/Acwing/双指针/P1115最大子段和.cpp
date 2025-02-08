#include <iostream>
#include <algorithm>
using namespace std;
int n, a, f, ans = -100000;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        f = max(f + a, a);
        ans = max(ans, f);
    }
    cout << ans << endl;

    return 0;
}