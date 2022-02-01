/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
class Solution {
public:
//solution1-迭代两次,将dp结果融合到然后使用121想法，dp
    int maxProfit(vector<int>& prices) {
        vector<int> dp(prices.size());//i之前能获得的最大值
        int max_p = prices[0],min_p = prices[0];
        for(int i = 1;i < prices.size();++i){ 
            dp[i] = max(dp[i-1],max_p - min_p);
            int p = prices[i];
            if(p > max_p) max_p = p;
            else if(p < min_p){
                min_p = p;
                max_p = p;
            }
                
        }
        int res = max(dp[prices.size()-1],max_p - min_p);
        min_p = prices[0]-dp[0],max_p = prices[0];
        for(int i = 1;i < prices.size();++i){
            int p = prices[i] - dp[i];
            if(prices[i] > max_p) max_p = prices[i];
            else if(p < min_p){
                res = max(res,max_p - min_p);
                min_p = p;
                max_p = prices[i];
            }
        }
        res = max(res,max_p - min_p);
        return res;
    }
// solution2: 记录状态，写出状态转移方程 -- 参考答案，一遍即可
        int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy1 = -prices[0], sell1 = 0;
        int buy2 = -prices[0], sell2 = 0;
        for (int i = 1; i < n; ++i) {
            buy1 = max(buy1, -prices[i]);
            sell1 = max(sell1, buy1 + prices[i]);
            buy2 = max(buy2, sell1 - prices[i]);
            sell2 = max(sell2, buy2 + prices[i]);
        }
        return sell2;
    }
};
// @lc code=end

