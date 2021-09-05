/*
 * @lc app=leetcode.cn id=5847 lang=cpp
 *
 * [5847] 找到所有的农场组
 */

// @lc code=start
class Solution {
    vector<int> d{-1,0,1,0,-1};
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int> > res;
        for(int i = 0;i < land.size();++i){
            for(int j = 0;j < land[0].size();++j){
                if(land[i][j]) {
                    int x = i+1,y = j;
                    while(y<land[0].size()&&land[i][y]){
                        land[i][y] = 0;
                        ++y;
                    }
                    --y;
                    while(x<land.size()&&land[x][j]) {
                        for(int k = j;k <=y ;++k) land[x][k] = 0;
                        ++x;
                    }
                    --x;
                    res.emplace_back(vector<int>{i,j,x,y});
           
                }
            }
        }
        return res;
    }
};
// @lc code=end

