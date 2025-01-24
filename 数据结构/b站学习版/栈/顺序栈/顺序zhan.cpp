#include <iostream>

using namespace std;

class SeqStack
{
public:
    SeqStack(int size = 0)
        : mtop(0), mcap(size)
    {
        mpStack = new int[mcap];
    }
    ~SeqStack()
    {
        delete[] mpStack;                                                                                                                                                                                                                                                                                                                                                 
        mpStack = nullptr;
    }

public:
    void push(int val)
    {
        // 栈满了
        if (mcap == mtop)
        {
            expand(2 * mcap);
        }
        mpStack[mtop++] = val;
    }

    void pop()
    {
        // top==0
        if (mtop == 0)
            throw "stack is empty!";
        mtop--;
    }

    // 获取栈顶元素
    int top() const
    {
        if (mtop == 0)
            throw "stack is empty!";
        return mpStack[mtop - 1];
    }

    bool empty() const
    {
        return mtop == 0;
    }

    int size() const
    {
        return mtop;
    }

private:
    void expand(int size)
    {
        int *p = new int[size];                 // 建新指针
        memcpy(p, mpStack, sizeof(int) * mcap); //
        delete[] mpStack;
        mpStack = p;
        mcap = size;
    }

private:
    int *mpStack;
    int mtop;
    int mcap;
};
int main()
{
    SeqStack s;
    int arr[] = {1, 2, 3, 22, 3, 112};
    for (int v : arr)
    {
        s.push(v);
    }
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}