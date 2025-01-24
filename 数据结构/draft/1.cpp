#include <iostream>
using namespace std;

const int M = 10000;
int n; //顶点数
int s[M][M];//记录最优策略二维数组
double m[M][M];//记录最优值二维数组
double g[M][M];//记录各顶点之间权值的二维数组

void MinWeightTriangulation()
{
    for (int i = 1; i <= n; i++) //初始化
    {
        m[i][i] = 0;
        s[i][i] = 0;
    }
    for (int r = 2; r <= n; r++)//r为问题规模，r=2实际上有三个点 r为当前计算的链长（子问题规模）  
    {
        for (int i = 1; i <= n - r + 1; i++)//n-r+1为最后一个r链的前边界  
        {
            int j = i + r - 1; //计算前边界为r，链长为r的链的后边界  
            m[i][j] = m[i + 1][j] + g[i - 1][i] + g[i][j] + g[i - 1][j];//k=i
            s[i][j] = i;
            for (int k = i + 1; k < j; k++) //枚举k=i+1到j所有情况
            {
                double u = m[i][k] + m[k + 1][j] + g[i - 1][k] + g[k][j] + g[i - 1][j];
                if (m[i][j] > u)
                {
                    m[i][j] = u;
                    s[i][j] = k;
                }
            }
        }
    }
}

void Traceback(int i, int j)  //递归求解所有子问题的弦。
{
    if (i == j)
        return;
    Traceback(i, s[i][j]);
    Traceback(s[i][j] + 1, j);
    cout << "三角剖分顶点：V" << i - 1 << ",V" << j << ",V" << s[i][j] << endl;
}

int main()
{
    int i;
    int j;
    cout << "请输入顶点个数n：" << endl;
    cin >> n;
    n--;
    cout << "请依次输入各顶点的连接权值：" << endl;
    for (i = 0; i <= n; ++i)
    {
        for (j = 0; j <= n; ++j)
        {
            cin >> g[i][j];
        }
    }
    MinWeightTriangulation();
    cout << "最优三角剖分的权值和是:" << endl;
    cout << m[1][n] << endl;
    cout << "三角剖分顶点：" << endl;
    Traceback(1, n);
    return 0;
}