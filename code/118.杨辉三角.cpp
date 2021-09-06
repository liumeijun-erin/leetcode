/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > res{vector<int>{1}};
        if(numRows == 1) return res;
        for(int i = 2;i <= numRows;++i){
            vector<int> tmp{1};
            for(int j = 1;j < i-1;++j){
                tmp.emplace_back(res[i-2][j-1]+res[i-2][j]);
            }
            tmp.emplace_back(1);
            res.emplace_back(tmp);
        }
        return res;
    }
};
// @lc code=end

