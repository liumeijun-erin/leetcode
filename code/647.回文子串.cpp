/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
class Solution {
public:
    //solution1:动态规划
    //但是时间复杂度高，这样看浪费的部分在于子串非回文还要判断
    //因此solution2部分时间复杂度beats 100%
    /*int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int> > dp(n,vector<int> (n+1,0));
        for(int i = 0;i < n;++i) {
            dp[i][0]= 1;
            dp[i][1] = 1;
        }
        int res = n;
        for(int len = 2;len <= n;++len){
            for(int i = 0;i <= n-len;++i){
                if(s[i] == s[i+len-1]) dp[i][len] = dp[i+1][len-2];
                res += dp[i][len];
            }
        } 
        return res;
    }*/
    //solution2:参考答案，以每个点为中轴暴力
    int countSubstrings(string s) {
        int count = 0;
        for (int i = 0; i < s.length(); ++i) {
        count += extendSubstrings(s, i, i); // 奇数长度
        count += extendSubstrings(s, i, i + 1); // 偶数长度
        }
        return count;
    }
    int extendSubstrings(string s, int l, int r) {
        int count = 0;
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            --l;
            ++r;
            ++count;
        }
        return count;
    }
};
// @lc code=end

