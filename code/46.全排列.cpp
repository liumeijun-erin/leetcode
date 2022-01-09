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
    // void help(vector<int>& nums, int& pos, vector<vector<int> >& res) {
    //     if (pos == 0) {
    //         res.emplace_back(nums);
    //         return ;
    //     }
    //     --pos;
    //     help(nums, pos, res);
    //     for (int i = pos; i >= 0; --i) {
    //         swap(nums[i], nums[pos+1]);
    //         help(nums, pos, res);
    //         swap(nums[i], nums[pos+1]);
    //     }
    //     ++pos;
    // }
    // vector<vector<int>> permute(vector<int>& nums) {
    //     vector<vector<int> > res;
    //     int pos = nums.size()-1;
    //     help(nums,pos,res);
    //     return res;
    // }
};
// @lc code=end

