/*
 * @lc app=leetcode.cn id=5895 lang=cpp
 *
 * [5895] 获取单值网格的最小操作数
 */

// @lc code=start
class Solution {
public:
    //  理性分析到底选取哪一点作为最后目标点合适,策略：中位数
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size(),n = grid[0].size();
        vector<int> tmp;
        for(int i = 0;i < m;++i){
            for(int j = 0;j < n;++j){
                if((grid[i][j]-grid[0][0])%x) return -1;
                tmp.emplace_back(grid[i][j]);
            }
        }
        sort(tmp.begin(),tmp.end());
        int target = tmp[tmp.size()/2],res = 0;
        for(const int& n:tmp){
            res += abs(n-target)/x;
        }
        return res;
    }
};
// @lc code=end

