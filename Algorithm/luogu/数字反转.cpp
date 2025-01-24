#include <iostream>
#include <string>
using namespace std;
string s;
signed main()
{
    cin>>s;
    int len = s.size();
    if(s[0]=='-')
    {
        cout<<'-';
        while(s[len-1]=='0')
        {
            len--;
        }
        for (int i = len - 1; i >= 1; i--)
        {
            cout << s[i];
        }
    }
    else{
        while (s[len - 1] == '0')
        {
            len--;
        }
        for (int i = len - 1; i >= 0; i--)
        {
            cout << s[i];
        }
    }
    

    return 0;
}