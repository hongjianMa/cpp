#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;

void solve()
{
    int n, m;
    string name;

    while (cin >> n)
    {
        map<string, int> p;
        for (int i = 0; i < n; i++)
        {
            cin >> name;
        }
        cin >> m;
        while (m--)
        {
            int pri;
            for (int i = 0; i < n; i++)
            {
                cin >> pri >> name;
                p[name] += pri;
            }
            int rank = 1;
            map<string, int>::iterator it;
            for (it = p.begin(); it != p.end(); it++)
            {
                if (it->second > p["memory"])
                    rank++;
            }
            printf("%d\n", rank);
        }
        p.clear();
    }
}

int main()
{
    solve();
    return 0;
}