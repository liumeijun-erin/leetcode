/*
 * @lc app=leetcode.cn id=1332 lang=cpp
 *
 * [1332] 删除回文子序列
 */

// @lc code=start
class Solution {
public:
    // 本题不会--参考答案，充分利用条件
    // 本身是回文1，否则最多2 ：111...,222
    int removePalindromeSub(string s) {
        int i = 0, j = s.size()-1;
        while (i < j) {
            if (s[i++] != s[j--]) return 2;
        }
        return 1;
    }
};
// @lc code=end

