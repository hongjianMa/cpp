#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> PII;
const int N = 1e5 + 10;
vector<PII> sect;
void merge(vector<PII> &sect)
{
    vector<PII> res;
    int st = -2e9, ed = -2e9;
    sort(sect.begin(), sect.end());
    for (auto item : sect)
    {
        if (ed < item.first)  // 两个区间没有交集， 直接放入
        {
            if (st != -2e9) // 避免没有区间的特殊情况
            {
                res.push_back({st, ed});
            }
            st = item.first, ed = item.second;  
        }
        else  // 有交集， ed取较大的哪一个
        {
            ed = max(ed, item.second);
        }
    }
    if (st != -2e9)
    {
        res.push_back({st, ed});
    }
    sect = res;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int l, r;
        cin >> l >> r;
        sect.push_back({l, r});  // 存入区间
    }
    merge(sect); // 区间合并
    cout << sect.size() << endl;  // 输出合并后的区间个数
    return 0;
}