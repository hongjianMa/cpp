#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int N = 520;
int a[N], b[N], c[N];
int main()
{
    string A, B;
    cin >> A >> B;
    int len = max(A.size(), B.size());  // 获取两个数中长度长的那一个
    for (int i = A.length() - 1, j = 1; i >= 0; i--, j++)
    {
        a[j] = A[i] - '0';
    }
    for (int i = B.length() - 1, j = 1; i >= 0; i--, j++)
    {
        b[j] = B[i] - '0';
    }
    for (int i = 1; i <= len; i++)
    {
        c[i] += a[i] + b[i];
        c[i + 1] = c[i] / 10;  // 模拟进位
        c[i] %= 10;
    }
    if (c[len + 1])  //最后进位可能导致位数增加
        len++;

    for (int i = len; i >= 1; i--)
    {
        printf("%d", c[i]);
    }

    return 0;
}