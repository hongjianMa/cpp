#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
int n;

/**
 * 将字符串转换为哈希值
 * @param s 输入的字符串
 * @return 返回计算出的哈希值
 */
ull StringToHash(string s)
{
    ull code = 0, x = 131, y = 140814840257324663; // y是通过lensson2计算出来的最大的素数
    for (int i = 0; i < s.size(); i++)
        code = (code * x + (ull)s[i]) % y; // 使用哈希函数计算哈希值
    return code;
}

/**
 * lesson2函数处理一组字符串，计算它们的哈希值，并输出不重复的哈希值数量
 */
void lesson2()
{
    ull a[10005], ans, n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        a[i] = StringToHash(s);
    }
    sort(a, a + n);
    ans = unique(a, a + n) - a; // 去重，注意-a
    cout << ans;
}

/**
 * lesson3函数寻找并输出小于0xffffffffffffffff/131-131的最大素数
 */
void lesson3()
{
    ull a = 0xffffffffffffffff; // 定义a为最大的unsigned long long值
    a = a / 131 - 131;          // 计算目标范围的上限
    while (1)                   // 无限循环，直到找到素数
    {
        int f = 0;                         // 标记变量，用于标记是否找到因数
        for (ull i = 2; i <= sqrt(a); i++) // 检查从2到sqrt(a)的所有数字
        {
            if (a % i == 0) // 如果a能被i整除
            {
                f = 1; // 设置标记为1
                break; // 退出循环
            }
        }
        if (f == 0) // 如果没有找到因数
        {
            cout << a << endl; // 输出a
            return;            // 退出函数
        }
        a--; // 将a减1，继续检查下一个数字
    }
}

int main()
{
    lesson2();

    return 0;
}