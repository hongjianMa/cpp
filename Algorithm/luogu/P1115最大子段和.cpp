#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2e5+10;
int n, a[N], dp[N];
int ans = -1e9;
int main()
{
    cin>>n;
    for(int i = 1;i <=n;i++)
        cin>>a[i];
    for(int i = 1;i<=n;i++)
    {
        dp[i] = max(a[i], dp[i-1]+a[i]);
        ans = max(dp[i],ans); 
    }
    cout<<ans;


    return 0;
}