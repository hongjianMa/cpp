#include <iostream>
#include <vector>
#include <string>
using namespace std;
void construct()
{
    // 默认构造
    vector<int> a;
    vector<double> b;
    vector<string> c;

    // 带参数的构造
    int arr[] = {0, 1, 2, 3, 4};
    vector<int> vecArr1(arr, arr + 5);
    
    vector<int> vecArr2(5, 3);  // 5个3
    for(auto t:vecArr2)
    {
        cout<<t<<" ";
    }
    cout<<endl;
    vector<int> vecArr3(vecArr1);  // 拷贝构造
    for (auto t : vecArr3)
    {
        cout << t << " ";
    }
    cout<<endl;
    vector<int> vecArr4 = vecArr2;
    for (auto t : vecArr4)
    {
        cout << t << " ";
    }
}

int main()
{
    construct();

    return 0;
}