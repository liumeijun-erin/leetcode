/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 */

// @lc code=start
class Solution {
public:
    //本题不会，参考了答案:二维动态规划，状态数组+状态转移方程+边界
    //不要一味贪心然后补漏--可能后造成后面错误，事先想好能否贪心
    //tip1:二维动态规划写法：dp[i][j]对应string1i位及之前，string2j位及之前
    //s1: p[j] == '?' dp[i][j] = dp[i-1][j-1]
    //s2: p[j] == '*' dp[i][j] = dp[i][j-1]||dp[i-1][j] //!!!!!!这里不用遍历所有i-1,i-2....利用递归，i-1即可！！！！！！这个写法重要
    //s3: else dp[i][j] = dp[i-1][j-1] && p[j] == s[i]
    //border:dp[0][0] = 1;dp[0][j] return 当前均为星号;dp[i][0] = 0
    // tip2:边界值：""\n"******" m==0情况不会在遍历中更新，所以需要提前说好
    bool isMatch(string s, string p) {
        vector<vector<bool> > dp(s.size()+1,vector<bool> (p.size()+1,false));
        dp[0][0] = true;
        int j = 0;
        while(j < p.size()&&p[j] == '*') dp[0][++j] = true;
        j = 0;
        for(int i = 1;i <= s.size();++i){
            for(int j = 1;j <= p.size();++j){
                //cout<<i<<" "<<j<<endl;
                if(p[j-1] == '?') dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '*') dp[i][j] = dp[i-1][j] || dp[i][j-1];
                else dp[i][j] = p[j-1] == s[i-1] && dp[i-1][j-1];
            }
        }
        return dp[s.size()][p.size()];
    }
};
// @lc code =end

