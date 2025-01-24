#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e3 + 10;
int n, V;
int v[N], w[N];
int f[N];
int main()
{
    cin >> n >> V;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i] >> w[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = v[i]; j <= V; j++)
        {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    cout << f[V];

    return 0;
}