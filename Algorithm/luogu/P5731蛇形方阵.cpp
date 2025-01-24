#include<iostream>
#include<iomanip>
using namespace std;
int change[4][2] = {0,1,1,0,0,-1,-1,0};
int a[15][15];
signed main()
{
    int n,x = 1,y = 1,d = 0;
    cin>>n;
    for(int i = 1;i<=n*n;i++)
    {
        a[x][y]=i;
        int dx = x+change[d][0],dy = y + change[d][1];
        if(dx>n||dy>n||dx<1||dy<1||a[dx][dy]) d = (d+1)%4;
        x+=change[d][0],y+=change[d][1];
    }
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            cout<<setw(3)<<setfill(' ')<<a[i][j];
        }
        cout<<"\n";
    }
    return 0;
}