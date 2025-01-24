#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        unordered_map<int, int> freq; // 记录每个棍子的频次

        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            freq[a[i]]++;
        }

        vector<int> pairs; // 用来存放可以组成梯形的棍子长度

        // 查找频次至少为 2 的棍子
        for (auto &p : freq)
        {
            if (p.second >= 2)
            {
                pairs.push_back(p.first);
                //pairs.push_back(p.first);
                if (p.second >= 4)
                { // 如果有 4 根相同的棍子，直接输出
                    cout << p.first << " " << p.first << " " << p.first << " " << p.first << endl;
                    goto next_test_case;
                }
            }
        }

        // 如果有两种棍子的频次都是至少 2，构成一个等腰梯形
        if (pairs.size() >= 2)
        {
            cout << pairs[0] << " " << pairs[0] << " " << pairs[1] << " " << pairs[1] << endl;
        }
        else
        {
            cout << -1 << endl;
        }

    next_test_case:;
    }

    return 0;
}
