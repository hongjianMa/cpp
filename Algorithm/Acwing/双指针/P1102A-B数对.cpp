#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int n, c, s[N];

int main()
{
    cin >> n >> c;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    sort(s, s + n);
    int l = 0, r = 0;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        while (s[l] < s[i] - c && l < n)
            l++;
        while (s[r] <= s[i] - c && r < n)
            r++;
        if (s[i] - s[l] == c)
        {
            sum += r - l;
        }
    }
    cout << sum << endl;

    return 0;
}