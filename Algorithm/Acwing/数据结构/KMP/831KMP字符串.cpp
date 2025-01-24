#include <iostream>
using namespace std;
const int N = 1e6 + 10, M = 1e5 + 10;
char s[N], p[M];
int ne[N];
int n, m;
int main()
{
    cin >> m >> p + 1 >> n >> s + 1;    // 注意本题目输入
    for (int i = 2, j = 0; i <= m; i++) // ne[]数组初始化
    {
        while (j && p[i] != p[j + 1])
            j = ne[j];
        if (p[i] == p[j + 1]) // 继续匹配
            j++;
        ne[i] = j; //
    }
    for (int i = 1, j = 0; i <= n; i++)
    {
        while (j && s[i] != p[j + 1]) // 移动p串
            j = ne[j];
        if (s[i] == p[j + 1])
            j++;
        if (j == m) // 满足匹配条件
        {
            printf("%d ", i - j);
            j = ne[j];
        }
    }

    
    return 0;
}