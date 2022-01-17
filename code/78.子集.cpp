/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > res = {vector<int> {}};
        for (const int& num : nums) {
            // cout<<num<<endl;
            vector<vector<int> > tmp(res);
            for (vector<int>& v: tmp) {
                vector<int> tmp_v(v);
                tmp_v.emplace_back(num);
                res.emplace_back(tmp_v);
            }
        }
        return res;
    }
};
// @lc code=end

