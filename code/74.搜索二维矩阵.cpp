/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0,right = matrix.size(),mid,n = matrix[0].size()-1;
        while(left <= right - 1){
            mid = (right - left)/2 + left;
            if(matrix[mid][n] < target) left = mid+1;
            else if (matrix[mid][0] > target) right = mid;
            else break;
        }
        int row = mid;
        //cout<<mid<<endl;
        if(matrix[mid][n] < target||matrix[mid][0] > target) return false;
        left = 0;
        right = matrix[0].size();
        while(left <= right - 1){
            int mid = (right - left)/2 + left;
            if(matrix[row][mid] == target) return true;
            else if(matrix[row][mid] > target) right = mid;
            else left = mid + 1;
        }
        return false;
    }
    //[[1,3,5,7],[10,11,16,20],[23,30,34,50]]\n 11
};
// @lc code=end

