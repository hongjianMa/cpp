#include <iostream>

using namespace std;
const int N = 1e5+10;
int n, k,ans = 0;
int a[N];

bool check(const int x)
{
    int cnt = 0;
    for(int i = 1;i<=n;i++)
    {
        cnt += a[i]/x;
        if(cnt>=k) return true;
    }
    return false;
}
signed main()
{
    
    cin>>n>>k;
    int height = 0;
    for(int i = 1;i<=n;i++) 
    {
        scanf("%d", &a[i]);
        height = max(height,a[i]);
    }
    int l = 0,r = height+1;
    while(l+1!=r)
    {
        int mid = l+r>>1;
        if(check(mid)){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    cout<<l<<endl;
    return 0;
}