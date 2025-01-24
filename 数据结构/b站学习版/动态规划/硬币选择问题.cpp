#include<iostream>

using namespace std;

int main()
{
    int v[] = {1, 3, 5};
    int length = sizeof(v) / sizeof(v[0]);
    const int c = 11;
    int *dp = new int [c+1]();
    for(int i = 1;i<=c;i++) {
        dp[i] = i; // 表示初始全部由1分硬币构成
        for(int j = 0;j<length;j++)
        {
            if(i>v[j]&&dp[i] > dp[i-v[j]]+1) {
                dp[i] = dp[i-v[j]] +1;
            }
        }
    }
    cout<<dp[c]<<endl;
    delete[] dp;

    return 0;
}