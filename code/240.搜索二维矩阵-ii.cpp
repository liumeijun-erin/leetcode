/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution {
public:
    // solution1：可以针对每一行进行二分 O(mlogn)
    // solution2: 利用对角性质z字划分 O(m + n)
    // 仔细想好初始关系i= 0，j最右和遍历顺序，相当于用j保留每一行最右可能范围！！！
    // 相当于在每行二分基础上利用了竖直方向排序，排除了上一行最右之外的部分
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

