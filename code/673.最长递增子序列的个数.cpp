/*
 * @lc app=leetcode.cn id=673 lang=cpp
 *
 * [673] 最长递增子序列的个数
 */

// @lc code=start
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<pair<int,int> > dp(nums.size(),make_pair(1,1));
        int max_cnt = 1,res = 0;
        for(int i = 0;i < nums.size();++i){
            for(int j = i-1;j >= 0;--j){
                if(nums[i] > nums[j]){
                    if(dp[i].first < dp[j].first+1) {
                        dp[i].first = dp[j].first + 1;
                        dp[i].second = dp[j].second;
                    }
                    else if(dp[i].first == dp[j].first+1){
                        dp[i].second += dp[j].second;
                    }
                }
            }
            if(max_cnt < dp[i].first) {
                max_cnt = dp[i].first;
                res = dp[i].second;
            }
            else if(max_cnt == dp[i].first){
                res += dp[i].second;
            }
        }
        return res;
    }
};
// @lc code=end

