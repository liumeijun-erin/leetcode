/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        else if(nums.size() == 2) return max(nums[1],nums[0]);
        else if(nums.size() == 3) return max(nums[0],max(nums[1],nums[2]));
        vector<int> dp(nums.size());
        dp[1] = nums[1];
        dp[2] = nums[2];
        int res = max(dp[1],dp[2]);
        for(int i = 3;i < nums.size();i++){
            dp[i] = max(dp[i-3],dp[i-2]) + nums[i];
            res = max(res,dp[i]);
        }
        dp[0] = nums[0];
        dp[1] = 0;
        dp[2] = nums[0]+nums[2];
        res = max(res,dp[2]);
        for(int i = 3;i < nums.size()-1;i++){
            dp[i] = max(dp[i-3],dp[i-2]) + nums[i];
            res = max(res,dp[i]);
        }
        return res;
    }
};
// @lc code=end

