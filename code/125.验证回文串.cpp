/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0,j = s.size()-1;
        while(i < j){
            while(i < j&&(s[i]< '0'||s[i] > '9')&&(s[i] < 'a'||s[i]>'z')&&(s[i] < 'A'||s[i]>'Z')) ++i;
            while(i < j&&(s[j]< '0'||s[j] > '9')&&(s[j] < 'a'||s[j]>'z')&&(s[j] < 'A'||s[j]>'Z')) --j;
            if(i == j) break;
            if(s[i] >= 97) s[i] -= 32;
            if(s[j] >= 97) s[j] -= 32;
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
};
// @lc code=end

