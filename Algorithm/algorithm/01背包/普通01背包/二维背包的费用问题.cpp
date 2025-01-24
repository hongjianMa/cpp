#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e3 + 10;
int n, v, m;
int V[N], W[N], Value[N];
int f[110][110];
int main()
{
    cin >> n >> v >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> V[i] >> W[i] >> Value[i];
    }
    for (int i = n; i >= 1; i--)
    {
        for (int j = v; j >= V[i]; j--)
        {
            for (int k = m; k >= W[i]; k--)
            {

                f[j][k] = max(f[j][k], f[j - V[i]][k - W[i]] + Value[i]);
            }
        }
    }
    cout << f[v][m];

    return 0;
}