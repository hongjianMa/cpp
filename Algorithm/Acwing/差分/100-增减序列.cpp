
#include <iostream>
#include <algorithm>
#define LL long long
using namespace std;
const int N = 1e5 + 10;
int a[N], b[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = n; i > 1; i--)
        b[i] = a[i] - a[i - 1];
    LL pos = 0, neg = 0;
    for (int i = 2; i <= n; i++)
    {
        if (b[i] > 0)
            pos += b[i];
        else
            neg -= b[i];
    }
    cout << min(neg, pos) + abs(neg - pos) << endl;
    cout << abs(neg - pos) + 1 << endl;

    return 0;
}