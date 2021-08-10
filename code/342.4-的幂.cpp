/*
 * @lc app=leetcode.cn id=342 lang=cpp
 *
 * [342] 4的幂
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfFour(int n) {
        //分析特性，应该只有一个非0位，且1应该在奇数位即01010101
        //参考了答案：如何不用循环或者递归确定1是否在奇数位？
        //可以手酸
        return n > 0&&!(n&(n-1))&&(n&1431655765);
        //tip:分析4应该只有一个1可以手算01010101010101010101010101010101的十进制值1431655765然后应用
    }
};
// @lc code=end

