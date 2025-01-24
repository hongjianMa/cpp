#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e3+10;

int n;
int g[N][N];
int mem[N][N];
int dfs(int x, int y)
{
    if(x>n||y>x) return 0;
    if(mem[x][y]) return mem[x][y];

    int sum = 0;
    sum = max(g[x][y]+dfs(x+1, y), g[x][y] + dfs(x+1, y+1));
    mem[x][y] = sum;
    return sum;
}

int main()
{
    cin>>n;
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=i;j++)
        {
            cin>>g[i][j];
        }
    }
    int res = dfs(1, 1);
    cout<<res;

    return 0;
}