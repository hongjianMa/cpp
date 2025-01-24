#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> PII;
vector<PII> sect;

void merge(vector<PII> &sect)
{
    vector<PII> res;
    long long st = -1e10, ed = -1e10;
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
            ed = max(ed, (long long)seg.second);
    }
    if (st != -1e10)
    {
        res.push_back({st, ed});
    }
    sect = res;
}

int main()
{
    int n, l, r;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> l >> r;
        sect.push_back({l, r});
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