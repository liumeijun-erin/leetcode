/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
    vector<vector<int> > res;
public:
    void backtracking(vector<int>& nums,int level){
        if(level == nums.size() - 1) {
            res.emplace_back(nums);
            return;
        }
        for(int i = level;i < nums.size();++i){
            swap(nums[i],nums[level]);
            backtracking(nums,level + 1);
            swap(nums[i],nums[level]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        backtracking(nums,0);
        return res;
    }
};
// @lc code=end

