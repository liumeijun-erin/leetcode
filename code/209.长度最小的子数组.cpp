/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        /*vector<int> dp(nums);
        int len = 1;
        while (len <= nums.size()) {
            for (int i = nums.size()-1; i - len + 1 >= 0; --i) {
                if (dp[i] >= target) return len;
                if (i > 0) dp[i] = dp[i - 1] + nums[i];
            }
            ++len;
        }
        return 0;*/
        int p = 0, q = 0;
        int cur_sum = 0;
        int len = 0;
        while (q < nums.size()) {
            while (q < nums.size() && cur_sum < target) cur_sum += nums[q++];
            if (cur_sum < target) break;
            while (p < q && cur_sum - nums[p] >= target) cur_sum -= nums[p++];
            if (len == 0|| q-p < len) len = q-p;
            cur_sum -= nums[p++];
        }
        return len;
        //11\n[1,1,1,1,1,1,1,1]
    }
};
// @lc code=end

