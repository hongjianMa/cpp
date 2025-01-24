#include <iostream>

using namespace std;

int main()
{
    int n, x;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        int cnt = 0;
        while (x)
        {
            if (x % 2 == 1)
                cnt++;
            x >>= 1;
        }
        cout << cnt << " ";
    }

    return 0;
}