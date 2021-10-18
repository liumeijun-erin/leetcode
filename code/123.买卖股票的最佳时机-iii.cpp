/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
class Solution {
public:
//tip1:入栈条件判断好，不一定是单调栈
//迭代两次使用121想法，dp
    int maxProfit(vector<int>& prices) {
        //stack<pair<int,int> > s;
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
    //[6,1,3,2,4,7]
    //[1,4,2]
    //[7,6,4,3,1]
    //[3,2,6,5,0,3]
};
// @lc code=end

