/*
 * @lc app=leetcode.cn id=458 lang=cpp
 *
 * [458] 可怜的小猪
 */

// @lc code=start
class Solution {
public:
    //  本题不会，参考答案写法：转化所求为因变量进行dp完成极值问题！！！
    //  key-pnt：转化所求为因变量，然后存当前假设对应的最大可能获益，从而通过dp求极值问题；
    //  key-pnt：组合数计算
    //  key-pnt: 得到数学式子之写几部推导化简
    //  way1:key-pnt 1:!!!动态规划换个角度求极值问题,存给定条件能得到的最大，以此求最小！！
    //  dp[bucket_num][iter_time]->dp[pig_num][iter_time]
    //  思路：换个维度记录当前pig数在iter_time下能拆分出的最多buckets!!!
    //  边界：dp[0][i] = 1;dp[i][0] = 1
    //  状态转移：dp[i][j] = sum(k=0->i) dp[k][j-1] * C(i,k)
    //  tip1: !!!注意这里是加法逻辑
    //  tip2: key-pnt2组合数计算--C(i,0) = C(i,i) = 1; C(i,j) = C(i-1,j-1) + C(i-1,j)
    //  tip3: 组合数和dp一起算
    //  tip4:转换--记录最大，然后在计算过程中output：找到f(pig_num, iter_time) >= bucket成立的最小i。在计算过程中筛选！
    // int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
    //     if (buckets == 1) return 0;
    //     int max_pigs = buckets - 1; // 0-buckets-1
    //     int times = minutesToTest / minutesToDie;
    //     vector<vector<int> > combinations(buckets+1, vector<int>(buckets+1));
    //     combinations[0][0] = 1;
    //     vector<vector<int> > dp(buckets, vector<int> (times+1));
    //     for (int i = 0; i <= max_pigs; ++i) dp[i][0] = 1;
    //     for (int j = 0; j <= times; ++j) dp[0][j] = 1;
    //     for (int i = 1; i <= max_pigs; ++i) {
    //         combinations[i][0] = 1;
    //         combinations[i][i] = 1;
    //         for(int j = 1;j < i; ++j) {
    //             combinations[i][j] = combinations[i-1][j-1] + combinations[i-1][j];
    //         }
    //         for (int j = 1; j <= times; ++j) {
    //             for (int k = 0; k <= i; ++k) {
    //                 dp[i][j] += dp[k][j-1] * combinations[i][i-k];
    //             }
    //         }
    //         if (dp[i][times] >= buckets) return i;
    //     }
    //     return 0;
    // }
    // way2:参考答案纯数学解法：由上述公式推出
    // ！！！key-pnt3写几项出来可以看出dp(i,1) == 2^i, dp(i,2) == 3^i,
    // dp[i][j] = sum(k=0->i) dp[k][j-1] * C(i,k) = sum(k=0->i)(j^k * C(i,k)) = (j + 1) ^ i
    // tip：分析完基础关系之后可以通过数学推导简化！！！
    // dp[i][j] = (j + 1) ^ i
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int times = minutesToTest / minutesToDie;
        int pigs = ceil(log(buckets) / log(times + 1));
        return pigs;
    }
    // note：[a,b,c,d]--ab,ac 都死或者都不死也是一种有用结果
};
// @lc code=end

