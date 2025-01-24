#include <iostream>

using namespace std;
const int N = 1e5 + 10;
int head = -1;            // 头结点
int e[N], ne[N], idx = 0; // e[]:表示value， ne[]: next idx：当前索引

void addHead(int x) // 头插
{
    e[idx] = x;
    ne[idx] = head;
    head = idx;
    idx++;
}

void add(int k, int x) // 插在第k个元素后面
{
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx++;
}

void remove(int k)
{
    ne[k] = ne[ne[k]];
}

int main()
{
    int m;
    cin >> m;
    while (m--)
    {
        char ch;
        cin >> ch;
        if (ch == 'H')
        {
            int x;
            cin >> x;
            addHead(x);
        }
        else if (ch == 'D')
        {
            int k;
            cin >> k;
            if (k == 0)
            {
                head = ne[head];
            }
            else
                remove(k - 1);
        }
        else if (ch == 'I')
        {
            int x, k;
            cin >> k >> x;
            add(k - 1, x);
        }
    }
    for (int i = head; i != -1; i = ne[i])
    {
        cout << e[i] << " ";
    }

    return 0;
}