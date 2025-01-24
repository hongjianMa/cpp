#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 10;
int x[N], y[N];  
int vis[N];     // vis[i] = 1 表示第 i 行有皇后
int flag[N];    // flag[j] 记录当前行第 j 列是否被攻击到（使用当前行号作为标记）
int n, m, k;   
int ans;        

int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> x[i] >> y[i];
        vis[x[i]] = 1; // 标记第 x[i] 行有皇后
    }

    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue; // 如果当前行有皇后，整行都被攻击，跳过

        int sum = m; // 假设当前行所有 m 个格子都未被攻击

        // 遍历所有皇后，标记当前行被攻击的格子
        for (int j = 1; j <= k; j++)
        {
            // 标记皇后的列被攻击
            if (flag[y[j]] != i) // 如果当前列尚未在当前行被标记为攻击
                sum--;           // 减少未被攻击的格子数
            flag[y[j]] = i;      // 标记当前列在当前行已被攻击

            // 计算当前行被第 j 个皇后的对角线攻击的列
            if (i < x[j]) // 当前行在皇后所在行的上方
            {
                // 计算右下角对角线被攻击的列
                int col_right = y[j] + (x[j] - i);
                if (col_right >= 1 && col_right <= m)
                {
                    if (flag[col_right] != i) // 如果该列尚未被标记为攻击
                        sum--;                // 减少未被攻击的格子数
                    flag[col_right] = i;      // 标记该列为被攻击
                }

                // 计算左下角对角线被攻击的列
                int col_left = y[j] - (x[j] - i);
                if (col_left >= 1 && col_left <= m)
                {
                    if (flag[col_left] != i) // 如果该列尚未被标记为攻击
                        sum--;               // 减少未被攻击的格子数
                    flag[col_left] = i;      // 标记该列为被攻击
                }
            }
            else if (i > x[j]) // 当前行在皇后所在行的下方
            {
                // 计算右上角对角线被攻击的列
                int col_right = y[j] + (i - x[j]);
                if (col_right >= 1 && col_right <= m)
                {
                    if (flag[col_right] != i) // 如果该列尚未被标记为攻击
                        sum--;                // 减少未被攻击的格子数
                    flag[col_right] = i;      // 标记该列为被攻击
                }

                // 计算左上角对角线被攻击的列
                int col_left = y[j] - (i - x[j]);
                if (col_left >= 1 && col_left <= m)
                {
                    if (flag[col_left] != i) // 如果该列尚未被标记为攻击
                        sum--;               // 减少未被攻击的格子数
                    flag[col_left] = i;      // 标记该列为被攻击
                }
            }
            // 如果 i == x[j]，说明当前行有皇后，已经在前面跳过，不需要处理
        }
        ans += sum; // 将当前行未被攻击的格子数累加到答案中
    }
    cout << ans;
    return 0;
}
