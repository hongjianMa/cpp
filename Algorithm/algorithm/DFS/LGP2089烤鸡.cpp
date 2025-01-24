#include <iostream>

using namespace std;
int n, a[35], b[350][35];
int Index = 0;

void dfs(int x)
{
    if (x > 10)
    {
        int mySum = 0;
        for (int i = 1; i <= 10; i++)
        {
            mySum += a[i];
        }
        if (mySum == n)
        {
            for (int i = 1; i <= 10; i++)
            {
                b[Index][i] = a[i];
            }
            Index++;
        }
        return;
    }

    for (int i = 1; i <= 3; i++)
    {
        a[x] = i;
        dfs(x + 1);
        a[x] = 0;
    }
}

signed main()
{
    cin >> n;
    if (n < 10 || n > 30)
    {
        cout << 0;
    }
    else
    {
        dfs(1);
        cout << Index << endl;
        for (int i = 0; i < Index; i++)
        {
            for (int j = 1; j <= 10; j++)
            {
                printf("%d ", b[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}