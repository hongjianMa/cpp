#include <iostream>
#include <cstring>
#include<algorithm>
using namespace std;
int n,cnt1 = 0,cnt2 = 0,cnt3 = 0;
string s;
int main()
{
    
    cin>>n>>s;
    for(int i = 0;i<n-1;i++){
        if(s[i]=='V'&&s[i+1]=='K')cnt1++;
    }
    cnt3 = cnt1;
    string s2 = s;//´æÔ­À´µÄs
    for(int i = 0;i<n;i++){
        s = s2;
        cnt2 = 0;
        if(s[i]=='V'){
            s[i]='K';
        
        }
        else if(s[i]=='K')s[i] = 'V';
    
        for(int j = 0;j<n-1;j++){
            if(s[j]=='V'&&s[j+1]=='K')cnt2++;
        }
      
        cnt3 = max(cnt3,cnt2);
    }
    cout<<cnt3;


    return 0;
}