/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
class Solution {
public:
    //受到答案启发：使用01背包方法
    int findTargetSumWays(vector<int>& nums, int target) {
        int m = nums.size();
        target = accumulate(nums.begin(),nums.end(),target);
        if(target < 0) return 0;
        vector<vector<int> > dp(m+1,vector<int> (target+1));
        dp[0][0] = 1;
        for(int i  = 1; i<= m;++i){
            dp[i][0] = 1;
            for(int j = 0;j <= target;++j){
                if(j < 2*nums[i-1]) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j] + dp[i-1][j-2*nums[i-1]];
            }
        }
        return dp[m][target];
    }
};
//[1,2,1]\n0
//[0,0,0,0,0,0,0,0,1]\n1
//[100]\n-200
// @lc code=end

