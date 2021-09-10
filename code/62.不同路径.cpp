/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
public:
    // path[m-1][n]+path[m][n-1]
    int uniquePaths(int m, int n) {
        vector<int> path(n);
        path[0] = 1;
        for(int i = 0;i < m;++i){
            for(int j = 1;j < n;++j){
                if(path[j-1]) path[j] += path[j-1];
            }
        }
        return path[n-1];
    }
};
// @lc code=end

 