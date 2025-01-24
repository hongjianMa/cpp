#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, q;
    cin >> n >> q;
    vector<vector<int>> a(n + 1); // 初始化一共0到n
    while (q--)
    {
        int op, i, j, k;
        cin >> op;
        if (op == 1)
        {
            cin >> i >> j >> k;
            if (a[i].size() < j + 1)  // 如果这个寄包柜不够大
                a[i].resize(j + 1); // 就扩大新的寄包柜
            a[i][j] = k;
        }
        else
        {
            cin >> i >> j;
            cout << a[i][j] << endl;
        }
    }

    return 0;
}