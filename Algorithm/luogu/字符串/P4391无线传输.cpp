#include <iostream>
using namespace std;
const int N = 1e6 + 10;
int ne[N];
char s1[N];
int ans = 1;
int main()
{
    int n;
    cin >> n >> s1 + 1;
    char ch = s1[1];
    for (int i = 2, j = 0; i <= n; i++)
    {
        while (j && s1[i] != s1[j + 1])
            j = ne[j];
        if (s1[i] == s1[j + 1])
            j++;
        ne[i] = j;
    }
    cout << n - ne[n];

    return 0;
}