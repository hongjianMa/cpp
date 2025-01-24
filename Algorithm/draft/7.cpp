#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int minimum_obstacles_to_end(int L, int S, int T, int M, const std::vector<int> &obstacle_positions)
{
    // 标记障碍物的位置
    std::vector<bool> obstacles(L + T + 1, false);
    for (int pos : obstacle_positions)
    {
        obstacles[pos] = true;
    }

    // 初始化dp数组
    std::vector<int> dp(L + T + 1, INT_MAX);
    dp[0] = 0;

    // 动态规划转移
    for (int i = 1; i <= L + T; ++i)
    {
        for (int step = S; step <= T; ++step)
        {
            if (i - step >= 0 && dp[i - step] != INT_MAX)
            {
                dp[i] = std::min(dp[i], dp[i - step] + (obstacles[i] ? 1 : 0));
            }
        }
    }

    // 查找从L到L+T中的最小障碍物数量
    int min_obstacles = INT_MAX;
    for (int i = L; i <= L + T; ++i)
    {
        min_obstacles = std::min(min_obstacles, dp[i]);
    }

    return min_obstacles;
}

int main()
{
    int L, S, T, M;
    std::cin >> L;
    std::cin >> S >> T >> M;
    std::vector<int> obstacle_positions(M);
    for (int i = 0; i < M; i++)
    {
        std::cin >> obstacle_positions[i];
    }

    std::cout << minimum_obstacles_to_end(L, S, T, M, obstacle_positions) << std::endl;

    return 0;
}
