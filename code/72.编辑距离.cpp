/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        //参考答案重组了一下
        int m = word1.size(),n = word2.size();
        int i ,j;
        vector<vector<int> > dp(m+1,vector<int> (n+1));
        for(i = 0;i <= m;++i){
            for(j = 0;j <= n;++j){
                //这里注意边界条件思考好，然后合并不冲突的循环
                if(!i) dp[i][j] = j;
                else if(!j) {
                    dp[i][j] = i;
                }
                else{
                    if(word1[i-1] == word2[j-1]){
                        dp[i][j] = dp[i-1][j-1];
                        //其实也可以合并写到下面的min但没差太多
                    }
                    else{
                        dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
                    }
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

