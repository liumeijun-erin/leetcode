/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left(nums.size(),1);
        vector<int> right(nums.size(),1);
        for(int i = 0;i < nums.size();++i){
            if(i > 0) left[i] = left[i - 1]*nums[i-1];
            if(i < nums.size()-1) right[nums.size()-2-i] = right[nums.size()-i-1]*nums[nums.size()-i-1];
        }
        for(int i = 0;i  < nums.size();++i){
            left[i] *= right[i];
        }
        return left;
    }
};
// @lc code=end

