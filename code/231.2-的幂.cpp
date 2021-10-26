/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2 的幂
 */

// @lc code=start
class Solution {
public:
    //线段树可得，n&-n是该该偶数最大的2^k公约数
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        return n == (n&-n);
    }
};
// @lc code=end

