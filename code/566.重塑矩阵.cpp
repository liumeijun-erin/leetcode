/*
 * @lc app=leetcode.cn id=566 lang=cpp
 *
 * [566] 重塑矩阵
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(),n = mat[0].size();
        if(m*n != r*c) return mat;
        vector<vector<int> > res (r,vector<int> (c));
        for(int i = 0;i < m;++i){
            for(int j = 0;j < n;++j){
                res[(i*n + j)/c][(i*n + j)%c] = mat[i][j];
                //cout<<(i*m + j)/c<<" "<<(i*m + j)%c<<endl;
            }
        }
        return res;
    }
};
// @lc code=end

