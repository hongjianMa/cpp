#include <bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        stack<int> s1, s2;
        int ans = 0, s = 0;
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            if ((x & 1) == 1)
                s1.push(x);
            else
                s2.push(x);
        }
        if (s2.empty() && s1.size() == 1)
        {
            cout << 0 << endl;
            continue;
        }
        if(!s2.empty()) cout << 1 + s1.size() <<endl;
        // while (!s2.empty() || !s1.empty())
        // {
        //     if (!s2.empty())
        //     {
        //         s += s2.top();
        //         s2.pop();
        //         if ((s & 1) == 0)
        //         {
        //             ans++;
        //             while ((s & 1) == 1)
        //                 s /= 2;
        //         }
        //     }
        //     if (!s1.empty())
        //     {
        //         s += s1.top();
        //         s1.pop();
        //         if ((s & 1) == 0)
        //         {
        //             ans++;
        //             while ((s & 1) == 1)
        //                 s /= 2;
        //         }
        //     }
        // }
        // cout << ans << endl;
    }

    return 0;
}