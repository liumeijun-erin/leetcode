/*
 * @lc app=leetcode.cn id=405 lang=cpp
 *
 * [405] 数字转换为十六进制数
 */

// @lc code=start
class Solution {
public:
    string toHex(int num) {
        if(num == 0) return "0";
        bool isNeg = false;
        if(num < 0){
            if(num == -2147483648) return "80000000";
            num ^= -2147483648;
            isNeg = true;
        }
        string res = "";
        while(num){
            if(num%16<10) res.insert(res.begin(),num%16 + '0');
            else res.insert(res.begin(),(num%16-10) + 'a');
            num /= 16;
        }
        if(isNeg){
            while(res.size() < 8){
                res.insert(res.begin(),'0');
            }
            if(res[0]-'0'+8 < 10) res[0] = (res[0]-'0'+8) + '0';
            else res[0] = (res[0]-'0'-2) + 'a';
        }
        return res;
    }
};
// @lc code=end

