#include <bits/stdc++.h>

using namespace std;


bool cheack(int k, int i)
{
    int x = 1;
    while(x<k)
    {
        
    }
}

void solve()
{
    int n, k;
    cin >> n >> k;
    int len = 0;
    if(n==1)
    {
        cout<<1<<endl;
        cout<<1<<endl;
        return ;
    }
    while(1)
    {
        if(k-len<1||k+len>n) break;
        int l = k-1-len;
        int r = n-k-len;
        if(l%2&&r%2)
        {
            cout<<3<<endl;
            cout<<1<<" "<<l+1<<" "<<n-r+1<<endl;
            return ;
        }
        len++;
    }
    cout<<-1<<endl;

}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}