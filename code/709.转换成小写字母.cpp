/*
 * @lc app=leetcode.cn id=709 lang=cpp
 *
 * [709] 转换成小写字母
 */

// @lc code=start
class Solution {
public:
    string toLowerCase(string s) {
        int gap = 'a'-'A';
        for (char& c:s) {
            if (c >= 'A' && c <= 'Z') c += gap;
        }
        return s;
    }
};
// @lc code=end

