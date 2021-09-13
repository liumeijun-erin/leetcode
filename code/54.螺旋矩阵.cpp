/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        //note:需要细心考虑极限条件：只剩一行/一列/一点
        //参考答案优化：减少数学计算，不用每次i计算边界，而是维护up，down，left，right
        //tip：常用数学表达式使用变量存储值，减少计算
        vector<int> res;
        int m = matrix.size(),n = matrix[0].size();
        int left = 0,right = n-1,down =0,up = m-1;
        int i,j;
        for(i = 0;i < (m+1)/2;++i){
            if(down>up||left>right) break;
            for(j = left;j <= right;++j) res.emplace_back(matrix[down][j]);
            for(j = down + 1;j <= up ;++j) res.emplace_back(matrix[j][right]);
            if(up>down&&left<right) {
                for(j = right-1;j >= left;--j) res.emplace_back(matrix[up][j]);
                for(j = up- 1;j>down;--j) res.emplace_back(matrix[j][left]);
            }
            ++left;
            --right;
            --up;
            ++down;
        }
        return res;
        // [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
        // [[7],[9],[6]]
        // [[1],[2],[3],[4],[5],[6],[7],[8],[9],[10]]
        // [[1,2,3,4,5,6,7,8,9,10]]
        // [[1,11],[2,12],[3,13],[4,14],[5,15],[6,16],[7,17],[8,18],[9,19],[10,20]]
    }
};
// @lc code=end

