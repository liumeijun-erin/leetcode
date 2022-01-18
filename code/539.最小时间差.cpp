/*
 * @lc app=leetcode.cn id=539 lang=cpp
 *
 * [539] 最小时间差
 */

// @lc code=start
class Solution {
public:
    void transform (vector<string>& timePoints, vector<int>& times) {
        int hour, minute;
        for (const string& time: timePoints) {
            hour = stoi(time.substr(0,2));
            minute = stoi(time.substr(3,2));
            times.emplace_back(60 * hour + minute);
        }
    }
    int findMinDifference(vector<string>& timePoints) {
        vector<int> times;
        transform(timePoints, times);
        sort(times.begin(), times.end());
        int day_span = 24 * 60;
        int res = day_span;
        for (int i = 1; i < times.size(); ++i) {
            res = min(times[i] - times[i-1], res);
        }
        res = min(res, day_span - times.back()+times[0]);
        return res;
    }
};
// @lc code=end

