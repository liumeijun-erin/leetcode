/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> diff;
        for(int i = 1;i < prices.size();++i){
           diff.emplace_back(prices[i]-prices[i-1]);
        }
        int sum = 0;
        vector<int> dp(diff.size()+1);
        //注意这里遍历次序，以及含义确定：以i为结尾
        int max_i = 0;
        for(int i = 1;i <= diff.size();++i){
            dp[i] = max(dp[i-1]+diff[i-1],dp[max_i]+diff[i-1]);
            if(i >= 3) {
                if(dp[i-2] > dp[max_i]) max_i = i-2;
            }
            sum = max(sum,dp[i]);
        }
        return sum;
    }
    //solution2:状态机方法详见leetcode101
};
//[2,1,4]
// @lc code=end

