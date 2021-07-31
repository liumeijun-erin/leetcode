/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //审题是否n阶矩阵
        //仔细想好遍历顺序！如果用对角线框的话不要忽略了对角线上点右上和左下的部分
        int i = 0,j=  matrix[0].size() - 1;;
        /*while(i < m){        
            while(j >= 0){
                if(matrix[i][j] == target) return true;
                if(matrix[i][j] < target) {
                    break;
                }
                --j;
            }
            if(j < 0) break;
            ++i;
        }*/
        //tip:勿忘优化逻辑结构！
        while(i <  matrix.size() && j >= 0){
            if(matrix[i][j] == target) return true;
            if(matrix[i][j] < target) ++i;
            else --j;
        }
        return false;
    }
};
// @lc code=end

