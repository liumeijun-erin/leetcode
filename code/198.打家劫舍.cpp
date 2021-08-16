/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int max_num = nums[0];
        if(nums.size() == 1) return max_num;
        int a = 0,b = 0;
        for(const int& num:nums){
            int sum1 = a + num;
            int sum2 = b ;
            a = b;
            b = max(sum1,sum2);
            max_num = max(b,max_num);
        }
        return max_num;
    }
};
// @lc code=end

