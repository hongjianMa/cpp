#include<iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
const int N =1e3+10;
int dp[N][N];
string s1,s2;
int LCS()
{
    memset(dp, 0, sizeof dp);
    for(int i = 1;i<=s1.size();i++)
    {
        for(int j = 1;j<=s2.size();j++)
        {
            if(s1[i-1]==s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[s1.size()][s2.size()];
}
int main()
{

    while(cin>>s1>>s2)
    {
        cout<<LCS()<<endl;
    }

    return 0;
}
