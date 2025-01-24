#include <iostream>
using namespace std;
signed main()
{
    double s,step = 2;
    cin>>s;
    int ans = 0;
    double threshold = 1e-6;
    while (s>threshold)
    {
        s-=step;
        ans++;
        step = step*0.98;
    }
    cout<<ans;
    return 0;
}