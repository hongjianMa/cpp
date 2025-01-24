#include <iostream>
#include <cstring>
using namespace std;
const int N = 1e6 + 10;
char s1[N], s2[N];
int ne[N];
int main()
{
    cin >> s1 + 1 >> s2 + 1;
    int n = strlen(s1 + 1), m = strlen(s2 + 1);
    for (int i = 2, j = 0; i <= m; i++)
    {
        while (j && s2[i] != s2[j + 1])
            j = ne[j];
        if (s2[i] == s2[j + 1])
            j++;
        ne[i] = j;
    }

    for (int i = 1, j = 0; i <= n; i++)
    {
        while (j && s1[i] != s2[j + 1])
            j = ne[j];
        if (s1[i] == s2[j + 1])
            j++;
        if (j == m)
        {
            printf("%d\n", i - j + 1);
            j = ne[j];
        }
    }
    for (int i = 1; i <= m; i++)
        cout << ne[i] << " ";

    return 0;
}