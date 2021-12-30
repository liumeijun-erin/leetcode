/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int dp = 0;
        for (const int& num: nums) {
            dp = dp>0? dp: 0;
            dp += num;
            res = max(res,dp);
        }
        return res;
    }
};
// @lc code=end

