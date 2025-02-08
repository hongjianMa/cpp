#include <iostream>
#include <set>
using namespace std;
set<int> a, b;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n;
        a.clear(), b.clear();
        for (int i = 1; i <= n; i++)
        {
            cin >> x;
            a.insert(x);
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> x;
            b.insert(x);
        }
        if (a.size() + b.size() >= 4)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}