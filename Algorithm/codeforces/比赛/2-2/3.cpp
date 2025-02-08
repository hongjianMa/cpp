#include <bits/stdc++.h>
using namespace std;

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int t; 
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<long long>> a(n, vector<long long>(n));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cin >> a[i][j];
            }
        }

        // Precompute rev_sum[i][j] = sum from j to n-1 (0-based)
        vector<vector<long long>> rev_sum(n, vector<long long>(n + 1, 0));
        for (int i = 0; i < n; ++i)
        {
            for (int j = n - 1; j >= 0; --j)
            {
                rev_sum[i][j] = rev_sum[i][j + 1] + a[i][j];
            }
        }

        // Try to construct mex = n
        vector<bool> used(n, false);
        bool possible = true;
        for (int j = 1; j <= n - 1; ++j)
        {                  // j is 1-based time point (original j is 1..n-1)
            int s = n - j; // desired sum
            bool found = false;
            for (int i = 0; i < n; ++i)
            {
                if (!used[i] && rev_sum[i][j + 1] == s)
                { // j+1 is the next time after j
                    used[i] = true;
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                possible = false;
                break;
            }
        }
        if (possible)
        {
            int cnt = 0;
            for (bool b : used)
                cnt += b;
            if (cnt == n - 1)
            {
                cout << n << '\n';
                continue;
            }
        }

        // If not possible, collect all possible values
        unordered_set<long long> s;
        s.insert(0);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 1; j <= n - 1; ++j)
            { // j is 1..n-1 in time points, j+1 is up to n
                long long val = rev_sum[i][j + 1];
                s.insert(val);
            }
        }

        // Find mex
        long long mex = 0;
        while (s.count(mex))
        {
            mex++;
        }
        cout << mex << '\n';
    }
    return 0;
}