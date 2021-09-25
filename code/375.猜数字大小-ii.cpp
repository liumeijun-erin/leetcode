/*
 * @lc app=leetcode.cn id=375 lang=cpp
 *
 * [375] 猜数字大小 II
 */

// @lc code=start
class Solution {
public:
    int getMoneyAmount(int n) { 
        //极大极小值问题：本题不会写，参考了答案思路使用dp
        //没想好一个绝对保证最小又最大的策略，要想到!划分！子问题解决dp
        //因此根本在于设计状态dp和状态转移方程！
        //思路dp[i][j]在i-j之间保证能赢的最小钱数
        //方程dp[i][i] =0;dp[i][i+1]=i;dp[i][j] = min(for(k in [i,j]) k+dp[k+1,j])
        vector<vector<int> > dp(n+1,vector<int>(n+1,n*(n+1)/2));
        for(int i = 1;i <= n;++i) dp[i][i]=0;
        for(int k = 1;k < n;++k){
            for(int i = 1;i+k <= n;++i){   
                dp[i][i+k] = i + dp[i+1][i+k];
                for(int j = i+1;j<i+k;++j){
                    int tmp = max(dp[i][j-1],dp[j+1][i+k]) + j;
                    dp[i][i+k] = min(tmp,dp[i][i+k]);
                }
                dp[i][i+k] = min(dp[i][i+k],i+k+dp[i][i+k-1]);
                //cout<<i<<" "<<i+k<<" "<<dp[i][i+k]<<endl;   
            }
        }
        return dp[1][n];
    }
};
// @lc code=end

