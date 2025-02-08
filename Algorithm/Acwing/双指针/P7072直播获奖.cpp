// #include <iostream>
// #include <algorithm>
// using namespace std;
// const int N = 1e5 + 10;
// int a[N], n;
// int w = 0;

// bool cmp(int a, int b)
// {
//     return a > b;
// }

// int main()
// {
//     cin >> n >> w;
//     // w = w * 0.01;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> a[i];
//         int b = w * i * 0.01;
//         // int b = (int)w;
//         b = max(1, b);
//         sort(a + 1, a + 1 + n, cmp);
//         cout << a[b] << " ";
//     }

//     return 0;
// }
#include <iostream>
using namespace std;
// cosnt int N = 1e5 + 10;
int t[610], n, w;
int main()
{
    int temp;
    cin >> n >> w;
    for (int i = 1; i <= n; i++ )
    {
        cin >> temp;
        t[temp] ++;  // 把分数放进桶里
        int sum = 0;
        for (int j = 600; j >= 0; j--)
        {
            sum += t[j]; // 从高往低枚举分数的人数
            if (sum >= max(1, i * w / 100))  // 人数大于获奖人数就输出
            {
                cout << j << " ";
                break;
            }
        }
    }


    return 0;
}
