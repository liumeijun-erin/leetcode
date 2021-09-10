/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m =obstacleGrid.size(),n = obstacleGrid[0].size();
        if(obstacleGrid[0][0]) return 0;
        obstacleGrid[0][0] = 1;
        for(int i = 0;i < m;++i){
            if(i!=0){
                if(obstacleGrid[i][0]) obstacleGrid[i][0]=0;
                else obstacleGrid[i][0] = obstacleGrid[i-1][0];
            }
            for(int j = 1;j < n;++j){
                if(obstacleGrid[i][j]) obstacleGrid[i][j]=0;
                else{
                    obstacleGrid[i][j] = obstacleGrid[i][j-1];
                    if(i !=0 ) obstacleGrid[i][j] += obstacleGrid[i-1][j];
                }
            }
        }
        return obstacleGrid[m-1][n-1];
    }
};
// @lc code=end

