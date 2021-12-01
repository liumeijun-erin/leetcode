/*
 * @lc app=leetcode.cn id=1446 lang=cpp
 *
 * [1446] 连续字符
 */

// @lc code=start
class Solution {
public:
    int maxPower(string s) {
        char c = s[0];
        int len = 1,cur_len = 0;
        for (const char& ch: s) {
            if (ch == c) ++cur_len;
            else {
                len = max(cur_len, len);
                c = ch;
                cur_len = 1;
            }
        }
        len = max(cur_len, len);
        return len;
    }
};
// @lc code=end

