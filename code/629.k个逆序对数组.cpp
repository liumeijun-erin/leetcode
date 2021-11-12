/*
 * @lc app=leetcode.cn id=629 lang=cpp
 *
 * [629] K个逆序对数组
 */

// @lc code=start
class Solution {
public:
    // 策略： 二维动态规划 dp[n][k]!!!联系n和n-1关系将n插入原来已经分好组的部分，插在倒数第n位则多n对
    // n = n- 1
    // 状态转移方程： dp[n][k] = sum (dp[n-1][k - n + 1] ...dp[n-1][k])(dp[1][k] == 1;dp[n][0] == 1)
    // k-n+1 >= 0;且k应该<= (n-1)*n/2
    int kInversePairs(int n, int k) {
        vector<int> dp(k+1,0);
        int mod = 1000000007;
        dp[0] = 1;
        for (int i = 2;i <= n;++i) {
            //int upper_k = min(k, i*(i-1)/2);
            int tmp = 0;
            for (int kk = max(k-i+2,0);kk <= k;++kk) {
                tmp = ((long long) tmp + dp[kk]) % mod;
            }
            int low = max(k-i+2,0);
            for (int j = k;j >= 1;--j) { //注意逆序更新
                //int upper_k_pre = min(j-1,(i-2)*(i-1)/2);
                if(low > 0) tmp = ((long long) tmp + dp[--low]) % mod;
                tmp = ((long long) tmp - dp[j] + mod) % mod;
                dp[j] = ((long long) dp[j] + tmp) % mod;
                
            }
        } 
        return dp[k];
        //time limit exceeded需要把加和部分再次化简成tmp形式
        //1000\n1000
    }
};
// @lc code=end

