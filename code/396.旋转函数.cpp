/*
 * @lc app=leetcode.cn id=396 lang=cpp
 *
 * [396] 旋转函数
 */

// @lc code=start
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int cur_res = 0, max_res = 0,sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            max_res += i*nums[i];
        }
        cur_res = max_res;
        for(int i = nums.size() - 1; i > 0; --i) {
            cur_res -= nums[i] * (nums.size() - 1);
            cur_res += (sum - nums[i]);
            max_res = max(max_res, cur_res);
        }
        return max_res;
    }
};
// @lc code=end

