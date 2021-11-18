/*
 * @lc app=leetcode.cn id=357 lang=cpp
 *
 * [357] 计算各个位数不同的数字个数
 */

// @lc code=start
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        if (n == 1) return 10;
        int sum = 10,pre = 9,cnt= 9;
        for(int i = 2; i <= n; ++i) {
            pre *= cnt;
            --cnt;
            sum += pre;
        }
        return sum;
    }
    //1
    //9
    //9 * 9 
    //9 * 9 * 8 
};
// @lc code=end

