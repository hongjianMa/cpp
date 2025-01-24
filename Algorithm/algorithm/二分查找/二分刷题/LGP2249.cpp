#include <iostream>
using namespace std;
const int N = 1e6 + 10;
int n, m, a[N];
int Bifind(const int &x)
{
    int l = 0, r = n + 1;
    while (l + 1 != r)
    {
        int mid = l + r >> 1;
        if (a[mid] < x)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    if (a[r] == x)
        return r;
    else
        return -1;
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    while (m--)
    {
        int x;
        scanf("%d", &x);
        printf("%d ", Bifind(x));
    }
    return 0;
}
