#include <bits/stdc++.h>
using namespace std;
int main()
{
    int64_t N, M;
    cin >> N >> M;
    int64_t max_g_candidate = M / N;
    int64_t ans = 0;
    for (int64_t i = 1; i * i <= M; ++i)
    {
        if (M % i == 0)
        {
            if (i <= max_g_candidate)
            {
                ans = max(ans, i);
            }
            int64_t j = M / i;
            if (j <= max_g_candidate)
            {
                ans = max(ans, j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}