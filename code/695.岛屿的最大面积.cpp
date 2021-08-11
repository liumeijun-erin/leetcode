/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<int> directions {-1,0,1,0,-1};
        int m = grid.size(),n = m?grid[0].size():0,area=0;
        for(int i = 0;i < m;++i) {
            for(int j = 0;j < n;++j){
                if(grid[i][j] == 1){
                    int localarea = 0;
                    stack<pair<int,int> > s;
                    s.push({i,j});
                    while(!s.empty()){
                        auto [island_x,island_y] = s.top();
                        s.pop();
                        if(island_x>=0 && island_x<m && island_y>=0 && island_y<n &&grid[island_x][island_y]){
                            grid[island_x][island_y] = 0;
                            ++localarea;
                            for(int k = 0;k < 4;++k){
                                s.push({island_x + directions[k],island_y+ directions[k+1]});
                            }
                        }
                    }
                    area =max(area, localarea);
                }
            }
        }
        return area;
    }
};
// @lc code=end

