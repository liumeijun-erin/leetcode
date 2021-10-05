/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        long long i = 1;
        while(i*i<=x) ++i;
        return i-1;
    }
};
// @lc code=end

