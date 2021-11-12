/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int pos_s = 0;
        for (const char&c: t) {
            if(c == s[pos_s]) {
                ++pos_s;
                if(pos_s == s.size()) break;
            }
        }
        return pos_s == s.size();
    }
};
// @lc code=end

