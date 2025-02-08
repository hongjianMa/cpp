#include <iostream>

using namespace std;
const int N = 2e6 + 10;
int a[N], q[N], n, k;
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int hh = 0, tt = 0;
    for (int i = 1; i <= n; i++)
    {
        while (hh < tt && i - q[hh] >= k)
            hh++;
        while (hh < tt && a[q[tt - 1]] < a[i])
            tt--;
        q[tt++] = i;
        // cout << " ----" << q[hh] << endl;
        // cout << " &&&& " << a[q[hh]] << endl;
        if (i >= k)
            cout << a[q[hh]] << endl;
    }

    return 0;
}