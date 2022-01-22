/*
 * @lc app=leetcode.cn id=233 lang=cpp
 *
 * [233] 数字 1 的个数
 */

// @lc code=start
class Solution {
  
public:
   public:
    // 本题不会，参考答案。按位计算
    // https://leetcode-cn.com/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof/solution/1n-zheng-shu-zhong-1-chu-xian-de-ci-shu-umaj8/
    int countDigitOne(int n) {
        int res = 0;
        long long mulk = 1;
        while (mulk <= n) {
            res += n/(mulk*10) * mulk;
            int tmp = n%(mulk*10)/mulk;
            if (tmp >= 2) res += mulk;
            else if (tmp == 1) res += n%(mulk*10) - mulk + 1;
            mulk *= 10;
        }
        return res;
    }
};
// @lc code=end

