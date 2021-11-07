/*
 * @lc app=leetcode.cn id=598 lang=cpp
 *
 * [598] 范围求和 II
 */

// @lc code=start
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        for(const vector<int>& pair:ops){
            m = min(m,pair[0]);
            n = min(n,pair[1]);
        }
        return m*n;
    }
};
// @lc code=end

