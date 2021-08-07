/*
 * @lc app=leetcode.cn id=326 lang=cpp
 *
 * [326] 3的幂
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 1) return true;
        if(n == 0) return false;
        if(n%3 != 0) return false;
        else return isPowerOfThree(n/3);
        //way2:利用对数fmod(log10(n) / log10(3), 1) == 0;
        //note：fmod由于double类型求余数
    }
};
// @lc code=end

