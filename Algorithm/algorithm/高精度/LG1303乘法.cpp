#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int N = 5010;
int a[N], b[N], c[N];
string A, B;
int main()
{
    cin >> A >> B;
    int lena = A.size(), lenb = B.size();
    for (int i = lena - 1; i >= 0; i--)
        a[lena - i] = A[i] - '0';
    for (int i = lenb - 1; i >= 0; i--)
        b[lenb - i] = B[i] - '0';
    int len = lena + lenb; // 两个数相乘位数不会超过两个数长度之和
    for (int i = 1; i <= lena; i++)
    {
        for (int j = 1; j <= lenb; j++)
        {
            c[i + j - 1] += a[i] * b[j];
        }
    }
    for (int i = 1; i <= len; i++)
    {
        c[i + 1] += c[i] / 10; // 处理进位
        c[i] %= 10;
    }
    for (; !c[len];)
        len--; // 去除前置0
    for (int i = max(1, len); i >= 1; i--)
    {
        cout << c[i];
    }

    return 0;
}