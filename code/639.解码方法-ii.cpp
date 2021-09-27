/*
 * @lc app=leetcode.cn id=639 lang=cpp
 *
 * [639] 解码方法 II
 */

// @lc code=start
class Solution {
    const int MAXN = 1000000007;
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1,0);
        dp[n] = 1;
        for(int i = n-1;i >= 0;--i){
            if(s[i] == '0') continue;
            else if(s[i] == '*'){
                for(int j = 0;j < 9;++j){
                    dp[i] = (dp[i]+dp[i+1])%MAXN;
                }
                if(i+1<n) {
                    if(s[i+1] == '*') {
                        for(int j = 0;j < 15;++j){
                            dp[i] = (dp[i]+dp[i+2])%MAXN;
                        }
                    }
                    else if(s[i+1] <= '6') {
                        for(int j = 0;j < 2;++j){
                            dp[i] = (dp[i]+dp[i+2])%MAXN;
                        }
                    }
                    else dp[i] = (dp[i]+dp[i+2])%MAXN;
                }
            }
            else if(s[i] == '1') {
                if(n+1 < n&&s[i+1] == '0') dp[i] = dp[i+2];
                else{
                    dp[i] = dp[i+1];
                    if(i+2<=n) {
                        if(s[i+1] == '*') {
                            for(int j = 0;j < 9;++j){
                                dp[i] = (dp[i]+dp[i+2])%MAXN;
                            }
                        }
                        else dp[i] = (dp[i]+dp[i+2])%MAXN;
                    }
                } 
            }
            else if(s[i] == '2') {
                if(n+1 < n&&s[i+1] == '0') dp[i] = dp[i+2];
                else{
                    dp[i] = dp[i+1];
                    if(i+2<=n) {
                        if(s[i+1] == '*') {
                            for(int j = 0;j < 6;++j){
                                dp[i] = (dp[i]+dp[i+2])%MAXN;
                            }
                        }
                        else if(s[i+1] <= '6') dp[i] = (dp[i]+dp[i+2])%MAXN;
                    }
                } 
            }
            else dp[i] = dp[i+1];
        }
        return dp[0];
        //"7*9*3*6*3*0*5*4*9*7*3*7*1*8*3*2*0*0*6*" overflow问题
    }
};
// @lc code=end

