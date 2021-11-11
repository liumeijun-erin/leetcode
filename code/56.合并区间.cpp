/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& v1, vector<int>& v2){
            return v1[0] < v2[0];
        });
        vector<vector<int> > res;
        int pos = 0, pre, next;
        while (pos < intervals.size()) {
            pre = intervals[pos][0];
            next = intervals[pos][1];
            ++pos;
            while (pos < intervals.size() && intervals[pos][0] <= next) {
                next = max(next, intervals[pos++][1]);
            } 
            res.emplace_back(vector<int> {pre, next});
        }
        return res;
    }
};
// @lc code=end

