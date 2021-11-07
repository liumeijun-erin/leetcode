/*
 * @lc app=leetcode.cn id=132 lang=cpp
 *
 * [132] 分割回文串 II
 */

// @lc code=start
class Solution {
public:
    //  本题不会：参考答案，使用二维动态规划 dp[i][j]和一维动态规划 cnt[i][j]结合！！！多存一点反而不会超时
    //  failed attempts
    //  简单遍历/bfs/dfs：超时"fifgbeajcacehiicccfecbfhhgfiiecdcjjffbghdidbhbdbfbfjccgbbdcjheccfbhafehieabbdfeigbiaggchaeghaijfbjhi"
    //  分析长段不行的时候 上一小段是否可以能构成left/right应该被存储
    //  这样的重复计算->使用一维动态dp[i]说明0-i划分为动态规划的次数
    //  答案思路：多存一点反而不会超时！保存所需的必要中间步骤然后再遍历
    //  使用二维动态规划 dp[i][j]:保存i-j是否为回文 其中当i >= j时候为true,否则状态转移方程为g[i+1][j-1] + 1:估计不会
    //  使用一维动态规划 f[i]= 0≤j<i min{f[j]}+1},其中 s[j+1..i] 是一个回文串
    int minCut(string s) {
        int n = s.size();
        vector<vector<int> > dp(n,vector<int> (n,0));
        for(int len = 0;len < n;++len){
            for(int i = 0;i + len < n;++i){
                if(s[i] == s[i+len]) {
                    if(i +1 < i + len -1) dp[i][i+len] = dp[i+1][i+len-1];
                    else dp[i][i+len] = 1;
                }
            }
        }
        vector<int> cnt(n,n);
        cnt[0] = 0;
        for(int i = 1;i < n;++i){
            if(dp[0][i]) cnt[i] = 0;
            else{
                for(int j = 0;j < i;++j){
                    if(dp[j+1][i]) cnt[i] = min(cnt[i],cnt[j] + 1);
                }
            }
        }
        return cnt[n-1];
    }
};
// @lc code=end

