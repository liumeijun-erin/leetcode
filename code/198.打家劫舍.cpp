/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int res = nums[0];
        if (nums.size() == 1) return res;
        res = max(res, nums[1]);
        if (nums.size() == 2) return res;
        
        nums[2] += nums[0];
        res = max(res, nums[2]);

        for(int i = 3; i < nums.size(); ++i) {
            nums[i] += max(nums[i-2], nums[i-3]);
            res = max(res, nums[i]);
        }
        return res;
    }
};
// @lc code=end

