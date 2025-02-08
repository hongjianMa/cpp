#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int, int> PII;
int n;
vector<PII> sect;
void merge(vector<PII> &sect)
{
    vector<PII> res;
    int st = -1e10, ed = -1e10;
    sort(sect.begin(), sect.end());
    for (auto seg : sect)
    {
        if (ed < seg.first)
        {
            if (st != -1e10)
            {
                res.push_back({st, ed});
            }
            st = seg.first, ed = seg.second;
        }
        else 
            ed = max(ed, seg.second);
    }
    if (st != -1e10)
    {
        res.push_back({st, ed});
    }
    sect = res;
}

signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        sect.push_back({a, b});
    }
    merge(sect);
    int res = 0;
    for (auto seg : sect)
    {
        res += seg.second - seg.first;
    }
    cout << res << endl;
    return 0;
}
