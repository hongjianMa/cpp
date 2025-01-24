#include <iostream>
#include <time.h>
using namespace std;

// 整形数组， 把偶数调到数组的左边，把奇数调到数组的右边
void AdjustArray(int arr[], int size)
{
    int *p = arr;
    int *q = arr + size - 1;
    while (p < q)
    {
        while (p < q)
        {
            if ((*p & 0x1) == 1) // 查奇数
                break;
            p++;
        }
        while (p < q)
        {
            if ((*q & 0x1) == 0) // 查偶数
                break;
            q--;
        }
        if (p < q)
        {
            int temp = *p;
            *p = *q;
            *q = temp;
            p++, q--;
        }
    }
}

int main()
{
    int arr[10] = {0};
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 100;
    }
    printf("调换之前：");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n调换之后：");

    AdjustArray(arr, 10);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}