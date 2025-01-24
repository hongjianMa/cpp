#include <iostream>
#include <cstring>
#include <time.h>
#include <stdlib.h>
using namespace std;

class myArr
{
public:
    myArr(int size = 10) : mCap(size), mCur(0)
    {
        mpArr = new int[mCap]();
    }
    ~myArr()
    {
        delete[] mpArr;
        mpArr = nullptr;
    }
    // 末尾添加元素
    void push_back(int val)
    {
        if (mCur == mCap)
        {
            expand(2 * mCap);
        }
        mpArr[mCur++] = val;
    }

    // 末尾删除元素
    void pop_back()
    {
        if (mCur == 0)
            return;
        mCur--;
    }

    // 按位置增加元素
    void insert(int pos, int val)
    {
        if (pos < 0 || pos > mCur)
        {
            throw "pos invalid!";
            return;
        }
        if (mCur == mCap)
        {
            expand(2 * mCap);
        }
        // 移动元素
        for (int i = mCur - 1; i >= pos; i--)
        {
            mpArr[i + 1] = mpArr[i];
        }
        mpArr[pos] = val;
        mCur++;
    }

    // 按位置删除元素
    void erase(int pos)
    {
        if (pos < 0 || pos >= mCur)
        {
            throw "pos invalid!";
            return;
        }
        for (int i = pos + 1; i < mCur; i++)
        {
            mpArr[i - 1] = mpArr[i];
        }
        mCur--;
    }

    // 元素查询
    int find(int val)
    {
        for (int i = 0; i < mCur; i++)
        {
            if (mpArr[i] == val)
                return i;
        }
        return -1;
    }

    // 打印数据
    void show()
    {
        for (int i = 0; i < mCur; i++)
        {
            cout << mpArr[i] << " ";
        }
        cout << endl;
    }

private:
    // 内部数组扩容接口
    void expand(int size)
    {
        int *p = new int[size];
        memcpy(p, mpArr, sizeof(int) * mCap);
        delete[] mpArr;
        mpArr = p;
        mCap = size;
    }

    int *mpArr; // 指向可扩容的数组内存
    int mCap;   // 数组容量
    int mCur;   // 当前数组有效元素个数
};
int main()
{
    myArr arr;
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        arr.push_back(rand() % 100);
    }
    arr.show();

    arr.pop_back();
    arr.show();

    arr.insert(0, 100);
    arr.show();

    arr.insert(10, 200);
    arr.show();

    int pos = arr.find(45);
    cout << pos << endl;

    return 0;
}