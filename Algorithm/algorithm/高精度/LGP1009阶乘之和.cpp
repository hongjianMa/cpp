#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int N = 5050;
string myAdd(string s1, string s2)
{
    int a[N] = {0}, b[N] = {0}, c[N] = {0};
    int lena = s1.size(), lenb = s2.size();
    for (int i = lena - 1; i >= 0; i--)
    {
        a[lena - i] = s1[i] - '0';
    }
    for (int i = lenb - 1; i >= 0; i--)
    {
        b[lenb - i] = s2[i] - '0';
    }
    int len = max(lena, lenb);
    for (int i = 1; i <= len; i++)
    {
        c[i] += a[i] + b[i];
        c[i + 1] = c[i] / 10;
        c[i] %= 10;
    }
    if (c[len + 1]) // 最后进位可以导致位数增加
        len++;
    string res;
    for (int i = len; i >= 1; i--)
    {
        res += to_string(c[i]);
    }
    return res;
}
string myMulity(string s1, string s2)
{
    int a[N] = {0}, b[N] = {0}, c[N] = {0};
    int lena = s1.size(), lenb = s2.size();
    for (int i = lena - 1; i >= 0; i--)
    {
        a[lena - i] = s1[i] - '0';
    }
    for (int i = lenb - 1; i >= 0; i--)
    {
        b[lenb - i] = s2[i] - '0';
    }
    int len = lena + lenb;
    for (int i = 1; i <= lena; i++)
    {
        for (int j = 1; j <= lenb; j++)
        {
            c[i + j - 1] += a[i] * b[j];
        }
    }
    for (int i = 1; i <= len; i++)
    {
        c[i + 1] += c[i] / 10;
        c[i] %= 10;
    }
    while (c[len] == 0)
        len--;
    string res;
    for (int i = max(1, len); i >= 1; i--)
    {
        res += to_string(c[i]);
    }
    return res;
}

string jiecheng(int x)
{
    if (x == 1 || x == 0)
        return "1";
    string num = "1";
    for (int i = 1; i <= x; i++)
    {
        num = myMulity(num, to_string(i));
    }
    return num;
}

int main()
{
    int n;
    cin >> n;
    string ans = "0";
    for (int i = 1; i <= n; i++)
    {
        ans = myAdd(ans, jiecheng(i));
    }
    cout << ans;

    return 0;
}
