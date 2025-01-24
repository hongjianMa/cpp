#include <bits/stdc++.h>
using namespace std;
bool func1(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '.')
        return true;

    return false;
}
bool func2(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '.' || c == '-')
        return true;

    return false;
}
string solve(string s)
{
    bool flag = 0;
    if (s[0] == '@' || s.back() == '@')
        return "No";
    string s1, s2;
    int i = 0;
    while (s[i] != '@'&&i<s.size())
    {
        s1 += s[i++];
        if (s[i] == '@')
            flag = 1;
    }
    if (!flag)
        return "No";
    i++;
    for (int j = i; j < s.size(); j++)
    {
        s2 += s[j];
    }
    if (s1.size() < 1 || s1.size() > 64 || s2.size() < 1 || s2.size() > 256)
        return "No";
    if (s1[0] == '.' || s2[0] == '.' || s2[0] == '-' ||
        s1.back() == '.' || s2.back() == '.' || s2.back() == '-')
        return "No";
    for (int i = 0; i < s1.size(); i++)
    {
        if (func1(s1[i]) == false)
            return "No";
    }
    for (int i = 0; i < s2.size(); i++)
    {
        if (func2(s2[i]) == false)
            return "No";
    }
    return "Yes";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        string ans = solve(s);
        cout << ans << endl;
    }

    return 0;
}