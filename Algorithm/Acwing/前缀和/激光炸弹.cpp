#include<iostream>

using namespace std;
const int N = 5e3+10;
int g[N][N],s[N][N];
int n,r;
int main()
{
    cin>>n>>r;
    for(int i = 1;i<=n;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        s[++x][++y] += z;
    }
    for(int i = 1;i<=5001;i++)
    {
        for(int j = 1;j<=5001;j++)
        {
            s[i][j] += s[i-1][j] + s[i][j-1] -s[i-1][j-1];
        }
    }
    int ans = 0;
    for (int i = r; i <= 5001; i++)
    {
        for (int j = r; j <= 5001; j++)
        {
            ans = max(ans, s[i][j] - s[i - r][j] - s[i][j - r] + s[i - r][j - r]);
        }
    }
    cout << ans << endl;

    return 0;
}