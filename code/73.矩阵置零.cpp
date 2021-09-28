/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //soluion1:使用o(m+n)空间
        /*int m =matrix.size(),n = matrix[0].size();
        vector<bool> isZeroRow(m,0);
        vector<bool> isZeroCol(n,0);
        for(int i = 0;i < m;++i){
            for(int j = 0;j < n;++j){
                if(matrix[i][j] == 0) {
                    isZeroRow[i] = true;
                    isZeroCol[j] = true;
                }
            }
        }
        for(int i = 0;i < m;++i){
            for(int j = 0;j < n;++j){
                if(isZeroRow[i]||isZeroCol[j]) {
                    matrix[i][j] = 0;
                }
            }
        }*/
        //solution2:使用第一行作为列标记（利用有零全零则用非零标记，无零则用零标记）;而行随第一次遍历即时更改
        int m =matrix.size(),n = matrix[0].size();
        int flag  = 0,i,j;
        for(j = 0;j < n;++j){
            if(!matrix[0][j]) {
                flag = 1;
                break;
            }
        }
        if(flag){
            for(j = 0;j < n;++j) {
                if(!matrix[0][j]) matrix[0][j] = flag;
                else matrix[0][j] = 0;
            }
        }
        for(i = 1;i < m;++i){
            bool hasZero = false;
            for(j = 0;j < n;++j){
                if(!matrix[i][j])  {
                    hasZero = true;
                    matrix[0][j] = flag;
                }
            }
            if(hasZero){
                for(j = 0;j < n;++j){
                    matrix[i][j] = 0;
                }   
            }
        }
        for(j = 0;j < n;++j){
            if(matrix[0][j] == flag){
                for(i = 0;i < m;++i){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
// @lc code=end

