/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        for(int i = 0;i < s.size();++i){
            if(s[i] == 'I') {
                if(i<s.size()-1&&s[i+1]=='V'||s[i+1]=='X') --res;
                else ++res;
            }
            else if(s[i] == 'V') res += 5;
            else if(s[i] == 'X') {
                if(i<s.size()-1&&s[i+1]=='L'||s[i+1]=='C') res -= 10;
                else res += 10;
            }
            else if(s[i] == 'L') res += 50;
            else  if(s[i] == 'C') {
                if(i<s.size()-1&&s[i+1]=='D'||s[i+1]=='M') res -= 100;
                else res += 100;
            }
            else if(s[i] == 'D') res += 500;
            else res += 1000;
        }
        return res;
    }
};
// @lc code=end

