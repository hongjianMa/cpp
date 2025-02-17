/* #include <iostream>
using namespace std;
#include <time.h>
const int N = 1e6;

bool shai[N];
int Prime[N];

int main()
{
    int cnt = 0;
    double t1 = clock();
    for(int i = 2;i<=N;i++)
    {
        if(!shai[i])
        {
            shai[++cnt] = i;
            for(int j = 2;j<=N;j++)
            {
                if(i*j>N)break;
                shai[i*j] = 1;//**素数的倍数不是素数。
            }
        }
    }
    double t2 = clock();
    cout<<cnt<<endl;
    cout<<t2-t1;
    return 0;
} */

//欧拉筛
#include <iostream>
using namespace std;
const int N = 1e6;
#include <time.h>
bool IsPrime[N];
int a[N];

int main()
{
    int cnt = 0;
    double t1 = clock();
    for(int i = 2;i<=N;i++)
    {
        if(!IsPrime[i]) a[++cnt] = i; 
            for(int j = 1;j<=cnt;j++)
            {
                if(i*a[j]>N)break;
                IsPrime[i*a[j]] = 1;
                if(i%a[j]==0) break;//这一步非常关键，可以去除重复筛元素
            }
        
    }
    double t2 = clock();
    cout<<cnt<<endl;
    cout<<t2-t1;
    return 0;
}
