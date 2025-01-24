#include <iostream>
using namespace std;

int f[20];

int main()
{
    int n;
    cin >> n;
    f[1] = 1;
    f[2] = 2;
    if (n == 1 || n == 2)
    {
        printf("%d", f[n]);
        return 0;
    }

    // for (int i = 3; i <= n; i++)
    // {
    //     f[i] = f[i - 1] + f[i - 2];
    // }
    // cout << f[n];

    // 用空间换时间
    int newf = 0, temp1 = 1, temp2 = 2;
    for(int i = 3; i<= n;i++)
    {
        newf = temp1 + temp2;
        temp1 = temp2;
        temp2 = newf;
    }
    printf("%d", newf);

    return 0;
}