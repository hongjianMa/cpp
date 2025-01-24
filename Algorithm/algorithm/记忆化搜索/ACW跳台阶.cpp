#include <iostream>
using namespace std;
const int N = 20;
int mem[N];
int dfs(int x)
{
    if(mem[x]) return mem[x];
    int sum = 0;
    if (x == 1)
        sum = 1;
    else if (x == 2)
        sum = 2;
    else
        sum = dfs(x - 1) + dfs(x - 2);
    mem[x] = sum;
    return sum;
}
int main()
{
    int n;
    cin >> n;
    int res = dfs(n);
    cout << res;

    return 0;
}