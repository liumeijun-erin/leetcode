/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,10001);
        dp[0] = 0;
        for(int i = 0;i < coins.size();i++){
            for(int j = coins[i];j <= amount;j++){
                dp[j] = min(dp[j],dp[j-coins[i]]+1);
            }
        }
        if(dp[amount] == 10001) return -1;
        else return dp[amount];
    }
};
// @lc code=end

