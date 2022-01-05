/*
 * @lc app=leetcode.cn id=1576 lang=cpp
 *
 * [1576] 替换所有的问号
 */

// @lc code=start
class Solution {
public:
    string modifyString(string s) {
        if (s.size() == 1) {
            if (s[0] == '?') s[0] = 'a';
            return s;
        }
        char pre = '?',next= s[1];
        for (int i = 0;i < s.size(); ++i) {
            if (s[i] == '?') {
                for (char j = 'a'; j <= 'z'; ++j) {
                    if (j != pre && j != next) {
                        s[i] = j;
                        break;
                    }
                }
            }
            pre = s[i];
            if (i+2 < s.size()) next = s[i+2];
        }
        return s;
    }
};
// @lc code=end

