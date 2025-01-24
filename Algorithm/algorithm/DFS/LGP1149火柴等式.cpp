#include <iostream>

using namespace std;
int n, cnt = 0;
bool st[22];
int num[1000] = {
    6,
    2,
    5,
    5,
    4,
    5,
    6,
    3,
    7,
    6};
int a[10010];
void dfs(int x, int sum)
{
    if (sum > n)
        return;
    if (x > 3)
    {
        if (a[1] + a[2] == a[3] && sum == n)
            cnt++;
        return;
    }

    for (int i = 0; i < 1000; i++)
    {
        a[x] = i;
        dfs(x + 1, sum + num[i]);
        a[x] = 0;
    }
}
int main()
{
    cin >> n;
    n -= 4;
    for (int i = 10; i < 1000; i++)
    {
        num[i] = num[i / 10] + num[i % 10];
    }
    dfs(1, 0);
    cout << cnt;

    return 0;
}