#include<bits/stdc++.h>
using namespace std;
const int N = 4e5+5;
int n,l,r;
int a[N];

int main()
{
    cin>>n>>l>>r;
    for(int i = 0;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i = n-l;i>=0;i--)
    {
        int s = -1e9;
        for(int j = l;j<=r;j++)
        {
            s = max(s, a[i+j]);
        }
        a[i] += s;
    }
    cout<<a[0]<<endl;

    return 0;
}