#include <iostream>
using namespace std;

const int N = 1010;
int m[N][N], q[N];              // m存储原始矩阵，q为单调队列的数组
int rowmin[N][N], rowmax[N][N]; // 存储每行滑动窗口的最小值和最大值
int colmin[N][N], colmax[N][N]; // 存储每列滑动窗口的最小值和最大值
int a, b, n, ans = 1e9;         // ans初始化为极大值

int main()
{
    cin >> a >> b >> n;
    // 读取输入矩阵
    for (int i = 1; i <= a; i++)
        for (int j = 1; j <= b; j++)
            cin >> m[i][j];

    // 处理每一行的滑动窗口最值
    for (int row = 1; row <= a; row++)
    {
        // 计算当前行的最大值
        int hh = 0, tt = 0; // 单调队列头尾指针
        for (int i = 1; i <= b; i++)
        {
            // 维护队列，移除超出窗口的元素
            while (hh < tt && q[hh] + n <= i)
                hh++;
            // 保持队列递减，移除尾部较小的元素
            while (hh < tt && m[row][q[tt - 1]] < m[row][i])
                tt--;
            q[tt++] = i;
            // 当i足够大时，保存当前窗口的最大值
            if (i >= n)
                rowmax[row][i - n + 1] = m[row][q[hh]];
        }

        // 计算当前行的最小值，逻辑类似最大值
        hh = 0, tt = 0;
        for (int i = 1; i <= b; i++)
        {
            while (hh < tt && q[hh] + n <= i)
                hh++;
            // 保持队列递增，移除尾部较大的元素
            while (hh < tt && m[row][q[tt - 1]] > m[row][i])
                tt--;
            q[tt++] = i;
            if (i >= n)
                rowmin[row][i - n + 1] = m[row][q[hh]];
        }
    }

    // 处理每一列的滑动窗口最值，基于rowmax和rowmin的结果
    for (int col = 1; col <= b - n + 1; col++)
    {
        // 处理当前列的最大值
        int hh = 0, tt = 0;
        for (int i = 1; i <= a; i++)
        {
            while (hh < tt && q[hh] + n <= i)
                hh++;
            // 比较的是rowmax中的值
            while (hh < tt && rowmax[q[tt - 1]][col] < rowmax[i][col])
                tt--;
            q[tt++] = i;
            if (i >= n)
                colmax[i - n + 1][col] = rowmax[q[hh]][col];
        }

        // 处理当前列的最小值
        hh = 0, tt = 0;
        for (int i = 1; i <= a; i++)
        {
            while (hh < tt && q[hh] + n <= i)
                hh++;
            // 比较的是rowmin中的值
            while (hh < tt && rowmin[q[tt - 1]][col] > rowmin[i][col])
                tt--;
            q[tt++] = i;
            if (i >= n)
                colmin[i - n + 1][col] = rowmin[q[hh]][col];
        }
    }

    // 遍历所有n×n区域，寻找最小差值
    for (int i = 1; i <= a - n + 1; i++)
        for (int j = 1; j <= b - n + 1; j++)
            ans = min(ans, colmax[i][j] - colmin[i][j]);

    cout << ans;
    return 0;
}