/*
 * @lc app=leetcode.cn id=1220 lang=cpp
 *
 * [1220] 统计元音字母序列的数目
 */

// @lc code=start
class Solution {
    int maxn = 1e9 + 7;
public:
    int countVowelPermutation(int n) {
        vector<long long> dp(5,1);
        vector<int> tmp(5);
        for (int i = 1; i <= n-1; ++i) {
            tmp[0] = dp[1];
            tmp[1] = (dp[0] + dp[2]) % maxn;
            tmp[2] = (dp[0] + dp[1] + dp[3] + dp[4]) % maxn;
            tmp[3] = (dp[2] + dp[4]) % maxn;
            tmp[4] = dp[0];
            for (int j = 0; j < 5; ++j) dp[j] = tmp[j];
        }
        long long res = 0;
        for (int i = 0; i < 5; ++i) res = (res + dp[i]) % maxn;
        return res;
    
    }
};
// @lc code=end

