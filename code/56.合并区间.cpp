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
        vector<int> tmp = intervals[0];
        for (const vector<int>& v: intervals) {
            if (v[0] > tmp[1]) {
                res.emplace_back(tmp);
                tmp = v;
            }
            else tmp[1] = max(v[1],tmp[1]);
        }
        res.emplace_back(tmp);
        return res;
    }
};
// @lc code=end

