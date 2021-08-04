/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */

// @lc code=start
class NumMatrix {
public:
    vector<vector<int> > sum;
    NumMatrix(vector<vector<int>>& matrix) {
        sum.resize(matrix.size());
        for(int i = 0;i < matrix.size();++i){
            sum[i].resize(matrix[0].size());
            partial_sum(matrix[i].begin(),matrix[i].end(),sum[i].begin());
        }
        for(int i = 1;i < matrix.size();++i){
            for(int j = 0;j < matrix[0].size();++j){
                sum[i][j] = sum[i][j] + sum[i-1][j];
            }
        }
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        //也可以通过多加一行0实现格式统一化
        if(!row1&&!col1) return sum[row2][col2];
        else if(!row1) return sum[row2][col2] - sum[row2][col1-1];
        else if(!col1) return sum[row2][col2] - sum[row1-1][col2];
        else return sum[row2][col2] + sum[row1-1][col1-1] - sum[row2][col1-1] - sum[row1-1][col2];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

