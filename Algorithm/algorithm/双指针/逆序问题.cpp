#include <iostream>
#include <cstring>
using namespace std;

// 字符串逆序
void Reverse(char arr[], int size)
{
    char *p = arr;
    char *q = arr + size - 1;
    while (p < q)
    {
        char ch = *p;
        *p = *q;
        *q = ch;
        p++;
        q--;
    }
    cout << arr << endl;
}

int main()
{
    char a[] = "helloworld";
    Reverse(a, strlen(a));

    return 0;
}