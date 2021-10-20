/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel 表列序号
 */

// @lc code=start
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res = 0;
        for(const char&c:columnTitle){
            res *= 26;
            res += (c-'A')+1;
        }
        return res;
    }
};
// @lc code=end

