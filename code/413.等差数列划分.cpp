/*
 * @lc app=leetcode.cn id=413 lang=cpp
 *
 * [413] 等差数列划分
 */

// @lc code=start
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        //一定要审题是否要求连续！
        vector<int> dp(nums.size(),0);
        for(int i = 2;i < nums.size();++i){
            if(nums[i] == 2 * nums[i -1] - nums[i-2]){
                dp[i] = dp[i - 1] + 1;
            }
        }
        return accumulate(dp.begin(),dp.end(),0);
    }
};
// @lc code=end

