#include <iostream>
#include <vector>

using namespace std;
string a, b;
vector<int> A, B;
vector<int> mul(vector<int> &A, vector<int> &B)
{
    vector<int> C(A.size() + B.size() + 10, 0); // 初始化， size设置大一点
    for (int i = 0; i < A.size(); i++)
        for (int j = 0; j < B.size(); j++)
        {
            C[i + j] += A[i] * B[j];  // 注意这里是 +=
        }

    int t = 0;
    for (int i = 0; i < C.size(); i++)
    {
        t += C[i];
        C[i] = t % 10;
        t /= 10;
    }

    // 去除前导0
    while (C.size() > 1 && C.back() == 0)
        C.pop_back();
    return C;
}
int main()
{
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i--)  // 倒序读入
    {
        A.push_back(a[i] - '0');
    }
    for (int i = b.size() - 1; i >= 0; i--)
    {
        B.push_back(b[i] - '0');
    }
    auto C = mul(A, B);
    for (int i = C.size() - 1; i >= 0; i--)
        printf("%d", C[i]);
    return 0;
}