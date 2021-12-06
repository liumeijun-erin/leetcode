/*
 * @lc app=leetcode.cn id=1816 lang=cpp
 *
 * [1816] 截断句子
 */

// @lc code=start
class Solution {
public:
    string truncateSentence(string s, int k) {
        int pos = 0;
        while (k--) {
            ++pos;
            pos = s.find(' ',pos);
        }
        if (pos != -1) return s.substr(0,pos);
        return s;
    }
};
// @lc code=end

