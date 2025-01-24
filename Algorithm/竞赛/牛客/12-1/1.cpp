#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int a[N];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int flag = 0;
        int x, y;
        cin >> x;
        for (int i = 1; i < 4; i++)
        {
            cin >> y;
            if (y != x)
                flag = 1;
        }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}