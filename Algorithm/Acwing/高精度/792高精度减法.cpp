#include <iostream>
#include <vector>
#include <string>
using namespace std;
string a, b;
vector<int> A, B;

bool cmp(vector<int> &A, vector<int> &B)
{
    if (A.size() != B.size())
        return A.size() > B.size();
    else
        for (int i = A.size() - 1; i >= 0; i--) // 这里是逆序
        {
            if (A[i] != B[i])
                return A[i] > B[i];
        }
    return true; // A = B
}

vector<int> sub(vector<int> &A, vector<int> &B)
{
    vector<int> C;
    for (int i = 0, t = 0; i < A.size(); i++) // 这里是i < A.size()
    {
        t = A[i] - t;
        if (i < B.size())
            t -= B[i];
        C.push_back((t + 10) % 10);
        if (t < 0)
            t = 1;
        else
            t = 0;
    }
    // 去除前导0
    while (C.size() > 1 && C.back() == 0)
        C.pop_back();
    return C;
}

int main()
{
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        A.push_back(a[i] - '0'); // 倒序存入
    }
    for (int i = b.size() - 1; i >= 0; i--)
    {
        B.push_back(b[i] - '0');
    }

    // 判断 A 是否大于等于 B
    if (cmp(A, B))
    {
        auto C = sub(A, B);
        for (int i = C.size() - 1; i >= 0; i--)
        {
            printf("%d", C[i]);
        }
    }
    else // A < B 结果为负数
    {
        auto C = sub(B, A);
        printf("-");
        for (int i = C.size() - 1; i >= 0; i--)
        {
            printf("%d", C[i]);
        }
    }

    return 0;
}