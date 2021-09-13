/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > res(n,vector<int>(n,0));
        int cur = 1;
        for(int i = 0;i < (n+1)/2;++i) {
            if(n%2&&i==(n+1)/2) res[i][i] = cur;
            else{
                for(int j = i;j < n - i;++j) res[i][j] = cur++;
                for(int j = i+1;j < n-i;++j) res[j][n-i-1] = cur++;
                for(int j = n-2-i;j>=i;--j) res[n-i-1][j] = cur++;
                for(int j = n-2-i;j > i;--j) res[j][i] = cur++;
            }
        }
        return res;
    }
};
// @lc code=end

