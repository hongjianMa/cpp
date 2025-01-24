#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int ans = 0;
        int index = 0;
        string t, s;

        cin >> s >> t;
        if (s[0] == t[0])
        {
            int len = min(s.size(), t.size());

            for (int i = 0, j = 0; i < len; i++, j++)
            {
                if (s[i] == t[j])
                {
                    index++;
                    ans++;
                }
                else
                    break;
            }

            ans++;
        }
        for (int i = index; i < s.size(); i++)
        {
            ans++;
        }
        for (int i = index; i < t.size(); i++)
        {
            ans++;
        }
        cout << ans << endl;
    }

    return 0;
}