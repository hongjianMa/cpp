#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    int lena = a.size(), lenb = b.size();
    vector<int> result(lena + lenb, 0);
    for (int i = lena - 1; i >= 0; i--)
    {
        for (int j = lenb - 1; j >= 0; j--)
        {
            int mul = (a[i] - '0') * (b[j] - '0');
            int sum = mul + result[i + j + 1];
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }
    bool flag = 0;
    int len = lena + lenb;
    string res;
    for (int num : result)
    {
        if (!flag && num == 0)
            continue;
        flag = 1;
        res.push_back(num + '0');
    }
    res = res.empty() ? "0" : res;
    cout << res;

    return 0;
}