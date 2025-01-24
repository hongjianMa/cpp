#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 这个函数用于执行两个大整数（以字符串形式表示）的乘法操作
string multiply(string num1, string num2)
{
    int n1 = num1.size();           // 第一个数的长度
    int n2 = num2.size();           // 第二个数的长度
    vector<int> result(n1 + n2, 0); // 结果数组，长度为两个数长度之和

    // 从最低位到最高位进行遍历，计算每一位的乘积并存储到结果数组中
    for (int i = n1 - 1; i >= 0; --i)
    {
        for (int j = n2 - 1; j >= 0; --j)
        {
            int mul = (num1[i] - '0') * (num2[j] - '0'); // 计算当前位的乘积
            int sum = mul + result[i + j + 1];           // 加上上一次的进位
            result[i + j + 1] = sum % 10;                // 当前位的值
            result[i + j] += sum / 10;                   // 进位
        }
    }

    string str;
    bool started = false; // 标记是否开始拼接结果字符串（用于跳过前导零）
    for (int num : result)
    {
        if (!started && num == 0)
            continue; // 跳过结果数组的前导零
        started = true;
        str.push_back(num + '0'); // 将数字转换为字符并拼接到结果字符串
    }
    return str.empty() ? "0" : str; // 如果结果字符串为空，返回"0"
}

// 计算给定数字n的阶乘并返回其字符串表示
string factorialToString(int n)
{
    string result = "1"; // 阶乘的初始值为1
    for (int i = 2; i <= n; ++i)
    {
        result = multiply(result, to_string(i)); // 逐个乘以2到n的数字
    }
    return result; // 返回计算好的阶乘字符串
}

int main()
{
    int t;
    cin >> t; // 输入测试案例的数量
    while (t--)
    {
        int n;
        char digit;
        cin >> n >> digit;                       // 输入n和要统计的数码
        string factorial = factorialToString(n); // 计算n的阶乘
        int count = 0;
        // 遍历阶乘的结果，统计数码digit出现的次数
        for (char c : factorial)
        {
            if (c == digit)
            {
                count++; // 如果字符匹配，计数器增加
            }
        }
        cout << count << endl; // 输出统计结果
    }
    return 0;
}
