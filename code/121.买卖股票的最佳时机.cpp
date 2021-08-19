/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_prices = prices[0],max_prices = prices[0],max_dif = 0;
        for(int i = 1;i < prices.size();++i){
            if(prices[i] < min_prices){
                max_dif = max(max_dif,max_prices - min_prices);
                min_prices = prices[i];
                max_prices = prices[i];
            }
            else if(prices[i] > max_prices){
                max_prices = prices[i];
            }
        }
        max_dif = max(max_dif,max_prices - min_prices);
        return max_dif;
    }
};
// @lc code=end

