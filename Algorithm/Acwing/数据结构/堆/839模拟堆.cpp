#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
const int N = 1e5 + 10;
int n, curSize;
int h[N];  // 堆
int ph[N]; // 存放第k个插入点的下标
int hp[N]; // 存放堆中点的插入次序
// 这个交换过程其实有那么些绕 但关键是理解 如果hp[u]=k 则ph[k]=u 的映射关系
// 之所以要进行这样的操作是因为 经过一系列操作 堆中的元素并不会保持原有的插入顺序
// 从而我们需要对应到原先第K个堆中元素
// 如果理解这个原理 那么就能明白其实三步交换的顺序是可以互换
// h,hp,ph之间两两存在映射关系 所以交换顺序的不同对结果并不会产生影响

void heap_swap(int u, int v)
{
    swap(h[u], h[v]);
    swap(hp[u], hp[v]);
    swap(ph[hp[u]], ph[hp[v]]);
}

void down(int u)
{
    int t = u;
    if (2 * u <= curSize && h[2 * u] < h[t])
        t = 2 * u;
    if (2 * u + 1 <= curSize && h[2 * u + 1] < h[t])
        t = 2 * u + 1;
    if (u != t)
    {
        heap_swap(u, t);
        down(t);
    }
}

void up(int u)
{
    if (u / 2 > 0 && h[u / 2] > h[u])
    {
        heap_swap(u, u / 2);
        up(u / 2);
    }
}

int main()
{
    cin >> n;
    int m = 0; // m用来记录插入的数的个数
               // 注意m的意义与cur_size是不同的 cur_size是记录堆中当前数据的多少
               // 对应上文 m即是hp中应该存的值
    while (n--)
    {
        string op;
        cin >> op;
        int x, k;
        if (op == "I")
        {
            int x;
            cin >> x;
            m++, curSize++;
            h[curSize] = x;
            hp[curSize] = m;
            ph[m] = curSize;
            up(curSize);
        }
        else if (op == "PM")
            cout << h[1] << endl;
        else if (op == "DM")
        {
            heap_swap(1, curSize);
            curSize--;
            down(1);
        }
        else if (op == "D")
        {
            cin >> k;
            int u = ph[k]; // 这里一定要用u=ph[k]保存第k个插入点的下标
            heap_swap(u, curSize);
            curSize--;
            up(u), down(u);
        }
        else if (op == "C")
        {
            cin >> k >> x;
            h[ph[k]] = x;
            down(ph[k]), up(ph[k]);
        }
    }
    return 0;
}