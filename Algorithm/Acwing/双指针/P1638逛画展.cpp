#include <iostream>
using namespace std;

const int N = 1e6 + 10;          // 定义最大图画数量
int n, m, l, r, sum[2010], a[N]; // 定义变量
int ans, ansl, ansr, num;        // ans: 最小门票价格，ansl和ansr: 最优区间，num: 当前区间内的不同画家数量

int main()
{
    // 输入图画总数 n 和画家数量 m
    cin >> n >> m;

    // 输入每幅画的画家编号
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    // 初始化双指针 l 和 r，分别表示区间的左端点和右端点
    l = 1, r = 1, ans = N; // ans 初始化为一个较大的值

    // 滑动窗口算法
    while (l <= r && r <= n + 1)
    {
        if (num < m)
        {                    // 如果当前区间内的不同画家数量不足 m
            r++;             // 右指针右移，扩大区间
            sum[a[r - 1]]++; // 统计当前画的画家出现次数
            if (sum[a[r - 1]] == 1)
                num++; // 如果该画家第一次出现，增加不同画家数量
        }
        else
        { // 如果当前区间内的不同画家数量已经达到 m
            if (ans > r - l)
            {                 // 如果当前区间的长度比之前的最优解更小
                ans = r - l;  // 更新最小门票价格
                ansl = l;     // 更新最优区间的左端点
                ansr = r - 1; // 更新最优区间的右端点
            }
            sum[a[l]]--; // 左指针右移，缩小区间，减少左端点画的画家出现次数
            if (sum[a[l]] == 0)
                num--; // 如果该画家的画不再出现在区间内，减少不同画家数量
            l++;       // 左指针右移
        }
    }

    // 输出最优区间的左端点和右端点
    cout << ansl << " " << ansr;
    return 0;
}