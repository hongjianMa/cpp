#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
string a;
int b;
vector<int> A;
vector<int> div(vector<int> &A, int b, int &r)
{
    vector<int> C;
    for (int i = A.size() - 1; i >= 0; i--) // 除法是从左往右，和另外三个不一样
    {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end());          // 这里要逆序过来，和另外三个算法保持一致
    while (C.size() > 1 && C.back() == 0) // 去除前导0
        C.pop_back();

    return C;
}
int main()
{
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        A.push_back(a[i] - '0');
    }
    int r = 0; // 余数
    auto C = div(A, b, r);
    for (int i = C.size() - 1; i >= 0; i--)
        printf("%d", C[i]);
    printf("\n%d", r);
    return 0;
}