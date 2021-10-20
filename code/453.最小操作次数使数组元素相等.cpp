/*
 * @lc app=leetcode.cn id=453 lang=cpp
 *
 * [453] 最小操作次数使数组元素相等
 */

// @lc code=start
class Solution {
public:
    int minMoves(vector<int>& nums) {
        long long sum = 0;
        int min_n = nums[0];
        for(const int&num:nums){
            sum += num;
            if(min_n > num) min_n = num;
        }
        sum -= min_n * nums.size();
        return sum;
    }
};
// @lc code=end

