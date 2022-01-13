/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */

// @lc code=start
class Solution {
public:
    //note:!!!vector中！！erase太多不可！！会超时!!!
    //solution1:两个二分+删除中间--由于有删除所以超时了--自作聪明--failed
    //solution2-直接遍历
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        bool pushed = false;
        for (const vector<int>& interval: intervals) {
            if (interval[1] < newInterval[0]) res.emplace_back(interval);
            else if (interval[0] > newInterval[1]) {
                if (!pushed){
                    res.emplace_back(newInterval);
                    pushed = true;
                }
                res.emplace_back(interval);
            }
            else {
                //interval[1] >= newInterval[0] && interval[0] <= newInterval[1]
                newInterval[0] = min(newInterval[0], interval[0]);
                newInterval[1] = max(newInterval[1], interval[1]);
            }
        }
        if (!pushed)  res.emplace_back(newInterval);
        return res;
    }
};
// @lc code=end

