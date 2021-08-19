/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        if(s == "" && (p == ""||p.size() == 2&&p[1] =='*')) return true;
        int m = s.size(),n = p.size();
        vector<vector<bool> > dp(m+1,vector<bool> (n+1,false));
        dp[0][0] = true;
        //note1：边界！补充！！！
        //!!!这里参考答案了，这里边界条件要写哈
        for(int i = 1;i <=n;++i){
            if(p[i-1] == '*') dp[0][i] = dp[0][i-2];
        }
        //明确含义，到i和到j完全对应上
        for(int i = 1;i <= m;++i){
            for(int j = 1;j <= n;++j){
                //note2：注意参考顺序,i在外面
                //且注意i从1开始s[i-1],p[j-1]
                if(p[j-1] == '.') dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '*'){
                    //tricky part!!!
                    if(p[j-2] == '.'||p[j-2] == s[i-1]) {
                        dp[i][j] = dp[i-1][j]||dp[i][j-2];//对应多个/没有
                    }
                    else dp[i][j] = dp[i][j-2];//对应没有
                }
                else{
                    dp[i][j] = (s[i-1]==p[j-1]) &&dp[i-1][j-1];
                }
            }
        }
        return dp[m][n];
    }
};
//"aa"\n"a*"
//"aab"\n"c*a*b"
//"a"\n".*..a*"
// @lc code=end

