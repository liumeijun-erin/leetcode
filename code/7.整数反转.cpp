/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    //2147483647
    int reverse(int x) {
        bool sign = false;
        if(x==-2147483648) return 0;
        if(x<0){
            x = -x;
            sign = true;
        }
        int res = 0;
        while(x){
            if(res > 214748364||res== 214748364&&(!sign&&x>7||sign&&x>8)){
                return 0;
            }
            res = res*10+x%10;
            x /= 10;
        }
        if(sign) res *= -1;
        return res;
    }
};
// @lc code=end

