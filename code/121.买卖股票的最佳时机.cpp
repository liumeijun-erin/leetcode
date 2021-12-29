/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        int low = prices[0],high = prices[0];
        int res = 0;
        for (const int& p: prices) {
            if (p < low) {
                res = max(res, high - low);
                low = p;
                high = p;
            }
            else if(p > high) high = p;
        }
        res = max(res, high - low);
        return res;
    }
};
// @lc code=end

