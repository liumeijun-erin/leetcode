`/*
 * @lc app=leetcode.cn id=693 lang=cpp
 *
 * [693] 交替位二进制数
 */

// @lc code=start
class Solution {
public:
    bool hasAlternatingBits(int n) {
        unsigned int a = 0xAAAAAAAA ,b=0x55555555;
        //注意说明unsigned
        //考虑0100情况
        if((n&b)==n||(n&a)==n) {
            if((n&a) == n) n >>= 1;
            while(n&1){
                if(n == 1) return true;
                n >>= 2;
            }
        }
        return false;
    }
};
// @lc code=end

