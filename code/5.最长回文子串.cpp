/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool> > dp(n+1,vector<bool> (n+1,false));
        int start = 0,len = 1;
        for(int i = 1;i <= n;++i) dp[i][0] = true;
        for(int i = 1;i <= n;++i){
            for(int j = 1;j + i -1 <=n;++j){
                if(i == 1) dp[j][i] = true;
                else if(s[j-1] == s[j+i-2]&&dp[j+1][i-2]){
                    dp[j][i] = dp[j+1][i-2];
                    start = j-1;
                    len = i;
                }
            }
        }
        return s.substr(start,len);
    }
    //todo:manacher's algorithm
};
// @lc code=end

