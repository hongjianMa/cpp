#include <iostream>

using namespace std;
const int N = 5e4+10;

//并查集
int f[N + 1];
int height[N + 1];
void initSet()  // 初始化
{
    for(int i =1;i<=N;i++)
    {
        f[i] = i;
        height[i] = 0;
    }
}

int findSet(int x)  //查找
{
    if(x != f[x]) x = findSet(f[x]);
    return f[x];
}


void unionSet(int x, int y)  // 合并
{
    x = findSet(x);
    y = findSet(y);
    if(height[x] == height[y])
    {
        height[x] += 1;
        f[y] = x;
    }
    else
    {
        if(height[x] < height[y])
        {
            f[x] = y;
        }
        else{
            f[y] = x;
        }
    }
}



int main()
{
    int n, m;
    int num = 1;
    while(1)
    {
        scanf("%d %d",&n,&m);
        if(n==0&&m==0) break;
        initSet();
        int x, y;
        for(int i = 1;i<=m;i++)
        {
            scanf("%d %d", &x, &y);
            unionSet(x, y);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (i == f[i])
                ans++;
        }
        cout << "Case " << num << ": " << ans << endl;
        num++;
    }

    return 0;
}