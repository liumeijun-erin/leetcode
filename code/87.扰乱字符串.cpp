/*
 * @lc app=leetcode.cn id=87 lang=cpp
 *
 * [87] 扰乱字符串
 */

// @lc code=start
class Solution {
public:
    //本题不会，参考了答案,注意写递归的时候发现有很多重叠子问题，所以使用高维动态规划
    //tip1：高维dp数组中len维度很有用！！！！
    //!!!!!!!!动态规划问题只要静下心写出状态和方程之后一步一步搞即可！
    //设计出记录子问题状态的数据结构之后很好办:dp[pos1][pos2][len]
    //分两种情况写状态转移方程 for i in(0,len) 
    //dp[pos1][pos2][len] = dp[pos1][pos2+len-i][i]&&dp[pos1+i][pos2][len-i]||dp[pos1][pos2][i]&&dp[pos1+i][pos2+i][len-i]
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        vector<vector<vector<bool> > > dp (n,vector<vector<bool> > (n,vector<bool> (n+1,0)) );
        for(int l = 1; l <= n;++l){
            for(int i = 0;i < n;++i){
                for(int j = 0;j < n;++j){
                    if(l == 1) dp[i][j][l] = (s1[i]==s2[j]);
                    int upper_k = n-i;
                    upper_k = min(upper_k,l);
                    for(int k = 1;k < upper_k;++k){
                        if(j+l-k<n&&dp[i][j+l-k][k]&&dp[i+k][j][l-k]||j+k<n&&dp[i][j][k]&&dp[i+k][j+k][l-k]) {
                            dp[i][j][l] = true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[0][0][s1.size()];
    }
    //"abcde"\n"caebd"
    //"abcdbdacbdac"\n"bdacabcdbdac"
    // 'abcdbdac bdacabcd'

};
// @lc code=end

