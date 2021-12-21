/*
 * @lc app=leetcode.cn id=1154 lang=cpp
 *
 * [1154] 一年中的第几天
 */

// @lc code=start
class Solution {
public:
    int dayOfYear(string date) {
        int year = 0, month = 0, day = 0;
        for (int i = 0; i < 4; ++i) year = 10 * year + (date[i]-'0');
        for (int i = 5; i < 7; ++i) month = 10 * month + (date[i]-'0');
        for (int i = 8; i < 10; ++i) day = 10 * day + (date[i]-'0');
        int month_len[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (month > 2) {
            if (year%4 == 0 &&(year%100 || year%400 == 0))  ++month_len[1];
        }
        int res = day;
        for (int i = 0; i < month-1; ++i) res += month_len[i];
        return res;
    }
};
// @lc code=end

