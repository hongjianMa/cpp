#include <iostream>
using namespace std;
const int N = 1e4 + 10;
int cnt = 0;
int a[N][4];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
    }

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < 3; j++)
        {
            if (a[i][j] == 1)
                sum++;
            if (sum >= 2)
            {
                cnt++;
                break;
            }
        }
    }

    cout << cnt;

    return 0;
}
