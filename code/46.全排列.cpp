/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
    vector<vector<int> > res;
public:
    //参考答案模板：巧妙之处在于使用nums本身作为状态记录，使用swap操作完成数值选择
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

