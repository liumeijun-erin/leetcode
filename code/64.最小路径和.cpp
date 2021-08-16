/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        //trick：空间压缩
        vector<int> num(grid[0].size());
        for(int i = 0;i < grid.size();++i){
            for(int j = 0;j < grid[0].size();++j){
                if(i == 0&&j == 0) {
                    num[j] = grid[i][j];
                }
                else if(i==0||j>0&&num[j-1] < num[j]){
                    num[j] = num[j-1] + grid[i][j];
                }
                else{
                    num[j] += grid[i][j];
                }
            }
        }
        return num.back();
    }
};
// @lc code=end

