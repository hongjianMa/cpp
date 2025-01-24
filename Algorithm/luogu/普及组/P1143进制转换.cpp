#include <iostream>
#include <string>
#include <cmath>
#include <stack>
using namespace std;
int n, m;
string s;
stack<int> ans;
int to_d(string s_, int n_)
{
    int a = 0;
    string s;
    for (int i = s_.size() - 1; i >= 0; i--)
    {
        s += s_[i];
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'A')
            a += 10 * pow(n_, i);
        else if (s[i] == 'B')
            a += 11 * pow(n_, i);
        else if (s[i] == 'C')
            a += 12 * pow(n_, i);
        else if (s[i] == 'D')
            a += 13 * pow(n_, i);
        else if (s[i] == 'E')
            a += 14 * pow(n_, i);
        else if (s[i] == 'F')
            a += 15 * pow(n_, i);
        else
            a += int(s[i] - '0') * pow(n_, i);
    }
    return a;
}

int main()
{
    cin >> n >> s >> m;
    int dec = to_d(s, n);
    // printf("%d", dec);
    while (dec)
    {
        ans.push(dec % m);
        dec /= m;
    }
    while (!ans.empty())
    {
        int temp = ans.top();
        ans.pop();
        if (temp >= 10)
        {
            switch (temp)
            {
            case 10:
                cout << 'A';
                break;
            case 11:
                cout << 'B';
                break;
            case 12:
                cout << 'C';
                break;
            case 13:
                cout << 'D';
                break;
            case 14:
                cout << 'E';
                break;
            case 15:
                cout << 'F';
                break;
            default:
                cout << temp;
                break; // Should never reach here
            }
        }
        else
        {
            cout << temp;
        }
    }
    return 0;
}