/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int  res = 0,num = x;
        while(num){
            if(res > 214748364||res== 214748364&&x>7){
                return false;
            }
            res = res*10+num%10;
            num /= 10;
        }
        return x == res;
    }
};
// @lc code=end

