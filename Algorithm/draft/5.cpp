#include <iostream>
#include <vector>
#include <climits> // For INT_MAX
using namespace std;

int minimumObstaclesToEnd(int L, int S, int T, int M, vector<int> &obstaclePositions)
{
    // 标记障碍物位置
    vector<bool> obstacles(L + T + 1, false);
    for (int pos : obstaclePositions)
    {
        obstacles[pos] = true;
    }

    // 初始化dp数组，dp[i]表示到达位置i时踩到的最小障碍物数量
    vector<int> dp(L + T + 1, INT_MAX);
    dp[0] = 0;

    // 动态规划转移
    for (int i = 1; i <= L + T; ++i)
    {
        for (int step = S; step <= T; ++step)
        {
            if (i - step >= 0)
            {
                dp[i] = min(dp[i], dp[i - step] + (obstacles[i] ? 1 : 0));
            }
        }
    }

    // 计算从位置L到L+T的最小障碍物数量
    int min_obstacles = INT_MAX;
    for (int i = L; i <= L + T; ++i)
    {
        min_obstacles = min(min_obstacles, dp[i]);
    }

    return min_obstacles;
}

int main()
{
    // 读取输入
    int L;
    cin >> L;
    int S, T, M;
    cin >> S >> T >> M;
    vector<int> obstaclePositions(M);
    for (int i = 0; i < M; ++i)
    {
        cin >> obstaclePositions[i];
    }

    // 计算结果并输出
    cout << minimumObstaclesToEnd(L, S, T, M, obstaclePositions) << endl;
    return 0;
}
