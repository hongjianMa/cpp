#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }
    while (!q.empty())
    {
        for (int i = 1; i < m; i++)
        {
            int x = q.front();
            q.pop();
            q.push(x);
        }
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}