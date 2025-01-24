#include <iostream>
#include <string>
#include <map>
using namespace std;
int n;
string s, ssum[1010];
map<string, int> m;
map<string, int>::iterator it;
int main()
{
    while (cin >> n && n != 0)
    {
        m.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> ssum[i];
            m[ssum[i]]++; // 遇到相同的字符串加一
        }
        int maxnum = 0;
        for (it = m.begin(); it != m.end(); it++)
        {
            if (it->second > maxnum)
            {
                maxnum = it->second;
                s = it->first;
            }
        }
        cout << s;
    }
    return 0;
}
