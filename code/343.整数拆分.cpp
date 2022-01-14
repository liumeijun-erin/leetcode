/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1,1);
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i/2; ++j) {
                int a = max(dp[j],j);
                int b = max(dp[i-j],i-j);
                dp[i] = max(dp[i],a*b);
            }
        }
        return dp[n];
    }
};
// @lc code=end

