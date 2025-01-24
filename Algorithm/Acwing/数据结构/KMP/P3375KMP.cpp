#include <iostream>
#include <string>
#include <cstring>
using namespace std;
const int N = 1e6 + 10, M = 1e6 + 10;
char s1[N], s2[M];
int ne[N];
int main()
{
    cin >> s1 + 1>> s2 +1;
    int len1 = strlen(s1 + 1), len2 = strlen(s2 + 1);
    // cout << len1 << " " << len2;
    for (int i = 2, j = 0; i<= len2; i ++ )
    {
        while (j && s2[i] != s2[j + 1]) j = ne[j];
        if(s2[i] == s2[j + 1]) j ++ ;
        ne[i] = j;
    }

    for (int i = 1, j = 0; i <= len1; i ++ )
    {
        while(j && s1[i] != s2[j + 1])
        {
            j = ne[j];
        }
        if(s1[i] == s2[j + 1]) j ++ ;
        if(j == len2) 
        {
            printf("%d\n", i - j + 1);
        }
    }
    for (int i = 1; i <= len2 ; i++)
    cout << ne[i] << " ";


    return 0;
}