/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            while (left <= right && nums[right] == val)
            {
                right--; // 从右边开始，找到不是val的位置
            }
            while (left <= right && nums[left] != val)
            {
                left++; // 从左边开始，找到是val的位置
            }
            if (left < right)
            { // 确保left在right左边，交换这两个元素
                swap(nums[left], nums[right]);
                left++;
                right--;
            }
        }
        return left;
    }
};
// @lc code=end
