/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字
 */

// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        return -accumulate(nums.begin(),nums.end(),-n*(n+1)/2);
    }
};
// @lc code=end

