/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        /*vector<int> dp(prices.size() + 1);
        int minp = 0,maxdp = 1,maxpre = 0;
        dp[0] = 0;
        dp[1] = -fee;
        for(int i = 2;i <= prices.size();++i){
            dp[i] = max(dp[maxdp]+prices[i-1]-prices[maxdp-1],max(0,dp[maxpre])+prices[i-1]-prices[minp]-fee);
            if(prices[minp] > prices[i-1]) {
                minp = i-1;
                maxpre = maxdp;
            }
            else if(dp[maxdp] <= dp[i]) {
                //使用了一个else效率提高很多
                maxdp = i;
                minp = i-1;
            }
        }
        return max(0,dp[maxdp]);
    }*/
        //改进：空间压缩
        //dp[maxdp],prices[maxdp-1],dp[maxpre],prices[minp]
        int minp = prices[0],maxdp = -fee,maxIndex = 1,maxpre = 0;
        for(int i = 2;i <= prices.size();++i){
            int dp = max(maxdp+prices[i-1]-prices[maxIndex],max(0,maxpre)+prices[i-1]-minp-fee);
            if(minp > prices[i-1]) {
                minp = prices[i-1];
                maxpre = maxdp;
            }
            else if(maxdp <= dp) {
                maxdp = dp;
                maxIndex = i-1;
                minp = prices[i-1];
            }
        }
        return max(0,maxdp);
        //[1,3,7,5,10,3]\n3
        //[9,8,7,1,2]\n3
        //[2,1,4,4,2,3,2,5,1,2]\n1
    } 
};
// @lc code=end

