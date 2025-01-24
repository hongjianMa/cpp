#include <iostream>
#include <vector>
#include <string>
using namespace std;

void ass()
{
    int a[] = {4, 3, 5, 1, 9};
    vector<int> v1, v2, v3, v4;
    v1.assign(a, a + 5);
    for (auto t : v1)
    {
        cout << t << " ";
    }
    cout << endl;

    v2.assign(v1.begin(), v1.end());
    for (auto t : v2)
    {
        cout << t << " ";
    }
    cout << endl;

    v3 = v2;
    for (auto t : v3)
    {
        cout << t << " ";
    }
    cout << endl;
}

int main()
{
    ass();

    return 0;
}
