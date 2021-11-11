/*
 * @lc app=leetcode.cn id=495 lang=cpp
 *
 * [495] 提莫攻击
 */

// @lc code=start
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int res = 0, pre = 0;
        for (const int& start:timeSeries) {
            if(pre < start) res += (start - pre);
            pre = start + duration;
        }
        return timeSeries.back() + duration - res;
    }
};
// @lc code=end

