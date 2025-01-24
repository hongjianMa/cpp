#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        int cnt0 = 0, cnt1 = 0, x;
        cin >> n;
        for (int i = 1; i <= 2 * n; i++)
        {
            cin >> x;
            x == 1 ? cnt1++ : cnt0++;
        }
        cout << cnt1 % 2 << " " << min(cnt1, cnt0) << endl;
    }

    return 0;
}