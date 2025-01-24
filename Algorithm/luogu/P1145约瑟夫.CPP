#include <iostream>
using namespace std;
const int N = 20;

int main()
{
    int k;
    cin >> k;
    int m = k;
    while (m++)
    {
        bool flag = false;
        int now = 0;
        for (int i = 0; i < k; i++)
        {
            now = (now - 1 + m) % (2 * k - i);
            if (now < k)
            {
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            cout << m << endl;
            return 0;
        }
    }

    return 0;
}