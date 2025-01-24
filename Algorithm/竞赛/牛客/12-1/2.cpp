#include <stdio.h>
#define N 10000
int main()
{
    char p[N];
    int n;
    scanf_s("%d", &n);
    char ch;
    for (int i = 0; i < n; i++)
    {
        scanf_s(" %c", &ch);
        p[i] = ch;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        printf("%c", p[i]);
    }
    printf("\n");
    return 0;
}