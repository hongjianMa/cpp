#include <bits/stdc++.h>

using namespace std;
const int N = 1e7 + 10;
bool checkpos(int x)
{
    if ((1000 <= x && x <= 9999) || (100000 <= x && x <= 999999))
        return 0;
    return 1;
}

bool checkBack(int x)
{
    int a[10], flag = 1;
    while (x)
    {
        a[flag++] = x % 10;
        x /= 10;
    }
    for (int i = 1; i <= flag / 2; i++)
    {
        if (a[i] != a[flag - i])
            return 0;
    }
    return 1;
}

bool checkPrime(int x)
{
    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int a, b;
    cin >> a >> b;
    if (a == 2)
    {
        printf("2\n");
    }
    if (a % 2 == 0)
        a++;
    b = min(b, 9999999);
    for (int i = a; i <= b; i += 2) // 枚举每一个奇数
    {
        if (!checkpos(i))
            continue;
        if (!checkBack(i))
            continue;
        if (!checkPrime(i))
            continue;
        printf("%d\n", i);
    }

    return 0;
}
