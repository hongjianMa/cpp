#include <iostream>

using namespace std;
bool st[20];
int arr[20];
int n;
void dfs(int x)
{
    if (x > n)
    {
        for (int i = 1; i <= n; i++)
        {
            if (arr[i])
            {
                printf("%5d", arr[i]);
            }
        }
        printf("\n");
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!st[i])
        {
            st[i] = true;
            arr[x] = i;
            dfs(x + 1);
            st[i] = false;
            arr[x] = 0;
        }
    }
}

int main()
{
    cin >> n;
    dfs(1);
    return 0;
}