#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    set<string> A, B; 
    while(cin>>n&&n)
    {
        string name;
        for(int i = 0;i<n;i++)
        {
            cin>>name;
            A.insert(name);
            cin>>name;
            A.insert(name);
            B.insert(name);
        }
        if(A.size() - B.size()==1) printf("Yes\n");
        else printf("No\n");
        A.clear(), B.clear();

    }
}
int main()
{
    solve();
    return 0;
}