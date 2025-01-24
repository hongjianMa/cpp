#include <iostream>
#include <algorithm>
using namespace std;
int n, s[1000], b[1000], res = 1e9;
int st[1000];
void dfs(int x)
{

    if (x > n)
    {
        int sum1 = 1; // 酸度
        int sum2 = 0; // 苦度
        bool isSelect = false;
        for (int i = 1; i <= n; i++)
        {
            if (st[i] == 1)
            {
                isSelect = true; //如果选了就要更新答案
                sum1 *= s[i];
                sum2 += b[i];
            }
        }
        if(isSelect)  //没有选择就不用更新答案
        {
            res = min(res, abs(sum1-sum2));
        }
        return ;
    }
    //  选
    st[x] = 1;
    dfs(x + 1);
    st[x] = 0;
    //  不选
    st[x] = 2;
    dfs(x + 1);
    st[x] = 0;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d", &s[i], &b[i]);
    }
    dfs(1);
    cout<<res;
    return 0;
}