#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t, a, b;

    cin >> t;
    while (t--)
    {
        int ans = 1e9;
        cin >> a >> b;
        if (a == b)
        {
            cout << 0 << endl;
            continue;
        }
        for (int i = a; i <= b; i++)
        {
            ans = min(ans, (i - a) + (b - i));
        }
        cout << ans << endl;
    }
}