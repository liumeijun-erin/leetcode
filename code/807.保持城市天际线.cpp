/*
 * @lc app=leetcode.cn id=807 lang=cpp
 *
 * [807] 保持城市天际线
 */

// @lc code=start
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> left(m,0);
        vector<int> front(n,0);
        int res = 0;
        for (int i = 0;i < m;++i) {
            for (int j = 0;j < n; ++j) {
                if (grid[i][j] > left[i]) left[i] = grid[i][j];
                if (grid[i][j] > front[j]) front[j] = grid[i][j];
            }
        }
        for (int i = 0;i < m;++i) {
            for (int j = 0;j < n; ++j) {
                res += min(left[i], front[j]) - grid[i][j];
            }
        }
        return res;
    }
};
// @lc code=end

