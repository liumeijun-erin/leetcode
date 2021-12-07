/*
 * @lc app=leetcode.cn id=1034 lang=cpp
 *
 * [1034] 边界着色
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m = grid.size(), n = grid[0].size();
        int d[5] = {-1,0,1,0,-1};
        queue<pair<int,int> > q;
        vector<vector<int>> visited(grid);
        int core = grid[row][col];
        q.emplace(make_pair(row, col));
        visited[row][col] = 0;
        while(!q.empty()) {
            bool border = false;
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int tmp_x = x + d[i];
                int tmp_y = y + d[i+1];
                if (tmp_x < 0||tmp_y < 0||tmp_x >= m||tmp_y >= n) border = true;
                else if(visited[tmp_x][tmp_y] == 0) continue;
                else if (grid[tmp_x][tmp_y] != core) border = true;
                else {
                    q.emplace(make_pair(tmp_x, tmp_y));
                    visited[tmp_x][tmp_y] = 0;
                }
            }
            if(border) grid[x][y] = color;
        }
        return grid;
    }
};
// @lc code=end

