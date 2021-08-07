/*
 * @lc app=leetcode.cn id=504 lang=cpp
 *
 * [504] 七进制数
 */

// @lc code=start
class Solution {
public:
    string convertToBase7(int num) {
        string res = "";
        bool minus = false;
        if(num == 0) return "0";
        if(num < 0){
            minus = true;
            num = -num;
        }
        while(num > 0){
            res  = to_string(num%7) + res;
            //atoi：stringToInt
            //to_string:intToString
            num /= 7;
        }
        if(minus) res = "-" + res;
        return res;
    }
};
// @lc code=end

