/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0,j = 0;
        while(i < nums.size()&&nums[i] != 0) ++i;
        for(j = i + 1;j < nums.size();++j){
            if(nums[j] != 0) nums[i++] = nums[j];
        }
        for(;i < nums.size();++i) nums[i] = 0;
    }
};
// @lc code=end

