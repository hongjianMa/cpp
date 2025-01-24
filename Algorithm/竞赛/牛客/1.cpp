#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int n, b[110], ans = 1e9, sum = 0;
// int num[] = {3, 4, 5, 6};
vector<int> answer;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ans = 1e9;
        answer.clear();
        memset(b, 0, sizeof b);
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            ++b[x];
        }
        bool found = false;
        for (int i = 0; i <= 100; i++)
        {
            if (b[i] >= 3)
            {
                ans = min(b[i], ans);
                sum = i * ans;
                answer.push_back(sum);
                found = true;
            }
        }
        sort(answer.begin(), answer.end());
        
        if (!found)
        {
            cout << "no" << endl;
        }
        else
        {
            sum = answer[0];
            cout << "yes" << endl;
            cout << sum << endl;
        }
    }
    return 0;
}
