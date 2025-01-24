#include <iostream>

using namespace std;
const int N = 1e6 + 10;
int minq[N], itt = -1,ihh, xhh maxq[N], xtt = -1;
int n, k, a[N];
int maxindex, minindex; 
int main()
{
    cin >> n >> k;
    for (int i =1; i<= n; i ++ ) cin >> a[i];
    int mmax = -1e9, mmin = 1e9;
    for(int i = 1; i <= k i ++ )
    {
        if(a[i] > mmax)
        {
            mmax = a[i], maxindex = i;
        }
        if(a[i] < mmin) 
        {
            mmin = a[i], minindex = i;
        }
        
    }
    minq[++itt] = mmin;
    maxq[++xtt] = mmax;
    for(int i = k + 1; i <= n; i ++ )
    {
        if(i-minindex<k && i - maxindex < k)
        {
            if(a[i] < minq[hh]) {
                minq[++tt] = a[i];
                hh++;
            }
            if(a[i] > maxq[hh]){
                maxq[++tt] = a[i];
            }
        }
    }

    return 0;
}