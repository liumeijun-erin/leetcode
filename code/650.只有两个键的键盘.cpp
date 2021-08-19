/*
 * @lc app=leetcode.cn id=650 lang=cpp
 *
 * [650] 只有两个键的键盘
 */

// @lc code=start
class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n+1,n+1);
        dp[1] = 0;
        for(int i = 1;i <= n;++i){
            int cnt = dp[i]+1,j = 2*i;
            while(j <= n) {
                dp[j] = min(++cnt,dp[j]);
                j += i;
            }
        }
        return dp[n];
    }
};
// @lc code=end

