/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stac;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '[' || s[i] == '(' || s[i] == '{')
            {

                stac.push(s[i]);
            }
            else
            {
                if (stac.empty())
                    return false;
                char ch = stac.top();
                if ((ch == '(' && s[i] != ')') || (ch == '[' && s[i] != ']') || (ch == '{' && s[i] != '}'))
                    return false;
                stac.pop();
            }
        }
        if (!stac.empty())
            return false;
        return true;
    }
};
// @lc code=end
