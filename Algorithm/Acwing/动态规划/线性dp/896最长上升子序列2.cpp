#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int cnt = 0, a[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        int l = 0, r = cnt;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (a[mid] >= x) // 找到左边比x要小的最大的位置 
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        if (l < cnt) // 情况1：找到的位置在最后一个位置左边
        {
            a[l] = x;
        }
        else // 情况2:最后一个位置比x小
            a[cnt++] = x;
    }
    cout << cnt << endl;
    return 0;
}