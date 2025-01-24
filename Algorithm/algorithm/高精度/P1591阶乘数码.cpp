#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string multiply(string s1, string s2)
{
    int a[5000] = {0}, b[5000] = {0}, c[5000] = {0};
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
    while (c[len] == 0 && len)
        len--;
    string res;
    for (int i = max(1, len); i >= 1; i--)
    {
        res += to_string(c[i]);
    }
    return res;
}

string toString(int n)
{
    if (n == 0 || n == 1)
        return "1";

    string res = "1";
    for (int i = 2; i <= n; i++)
    {
        res = multiply(to_string(i), res);
    }
    return res;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, cnt = 0;
        char a;
        cin >> n >> a;
        string ans = toString(n);
        for (int i = 0; i < ans.size(); i++)
        {
            if (ans[i] == a)
                cnt++;
        }
        cout << cnt << endl;
    }

    return 0;
}