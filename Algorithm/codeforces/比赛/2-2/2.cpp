#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }

        unordered_map<int, vector<int>> freq_map;
        for (int i = 0; i < n; ++i)
        {
            freq_map[a[i]].push_back(i);
        }

        vector<int> cost(k, -1); // Initialize the cost array with invalid values
        int cost_min = n;        // Minimum cost initialized to the highest possible value

        // Iterate through all values in the frequency map
        for (const auto &entry : freq_map)
        {
            vector<int> positions = entry.second;
            int m = positions.size();

            if (m < k)
                continue; // Skip if the number of occurrences is less than k

            vector<int> prefix_sum(m + 1, 0); // To store the number of elements up to each position
            for (int i = 0; i < m; ++i)
            {
                prefix_sum[i + 1] = prefix_sum[i] + (positions[i] - positions[i - 1] - 1);
            }

            int result = n;
            for (int i = 0; i <= m - k; ++i)
            {
                int cost = prefix_sum[i + k] - prefix_sum[i];
                result = min(result, cost);
            }
            cost_min = min(cost_min, result);
        }

        cout << cost_min << endl;
    }

    return 0;
}
