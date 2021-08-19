/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        //例题：参考答案转化为背包问题
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum&1) return false;
        sum /= 2;
        vector<bool> dp(sum + 1,false);
        dp[0] = true;
        for(int i = 0;i < nums.size();++i){
            for(int j = sum;j >= nums[i];--j){
                dp[j] = dp[j] || dp[j-nums[i]];
            }
        }
        return dp[sum];
    }
};
// @lc code=end

