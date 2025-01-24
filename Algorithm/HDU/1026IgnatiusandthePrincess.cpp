#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e3 + 10;

int main()
{
    int n, m;
    int a[N];
    while (cin >> n >> m)
    {
        for (int i = 1; i <= n; i++)
        {
            a[i] = i;
        }
        int b = 1;
        do
        {
            if (b == m)
                break;
            b++;
        } while (next_permutation(a + 1, a + 1 + n));

        for (int i = 1; i < n; i++)
            cout << a[i] << " ";
        cout << a[n] << endl;
    }

    return 0;
}