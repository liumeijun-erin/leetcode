/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文字符串 Ⅱ
 */

// @lc code=start
class Solution {
public:
    bool chance = true;
    bool validPalindrome(string s) {
        int i = 0,j = s.length() - 1;
        while(i < j){
            if(s[i] != s[j]){
                //要考虑到两边不能随便删一个，要考虑两种情况
                if(chance){
                    chance  = false;
                    return validPalindrome(s.substr(i,j-i))||validPalindrome(s.substr(i+1,j-i));
                }
                else return false;
            }
            else{
                ++i;
                --j;
            }
        }
        return true;
    }
};
// @lc code=end

