/*
 * @lc app=leetcode.cn id=1185 lang=cpp
 *
 * [1185] 一周中的第几天
 */

// @lc code=start
class Solution {
public:
    bool isLeapYear(int year) {
        return year%400 == 0 || year%100 && year%4==0;
    }
    string dayOfTheWeek(int day, int month, int year) {
        // 1971.1.1 Friday 365%7 = 1
        vector<int> days = {31,28,31,30,31,30,31,31,30,31,30,31};
        if (isLeapYear(year)) ++days[1];
        string wdays[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
        int interval = day + accumulate(days.begin(), days.begin()+month-1,0);
        for (int y = 1971; y < year; ++y) {
            if (isLeapYear(y)) interval += 2;
            else interval += 1;
        }
        interval = (interval - 1 + 4) % 7;
        return wdays[interval];
    }
};
// @lc code=end

