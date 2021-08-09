/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] 颠倒二进制位
 */

// @lc code=start
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int res = 0;
        int cnt = 32;
        while(cnt--){
            res <<= 1;
            res += n&1;
            n >>= 1;
        }
        //原本在这里增加了n的判断，！n则直接左移cnt，但表现反而不好
        return res;
    }
};
// @lc code=end

