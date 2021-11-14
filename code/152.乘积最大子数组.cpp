/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 1 && nums[0] < 0) return nums[0];
        vector<int> dp;
        vector<int> neg_pos;
        int mul = 1;
        int res = 0;
        for (int pos = 0; pos <= nums.size(); ++pos) {
            if (pos == nums.size() || nums[pos] == 0) {
                if (!dp.empty()) {
                    if (neg_pos.size()%2 == 0) res = max(res, mul);
                    else if (dp.size() > 1){
                        //cout<<neg_pos[0]<<endl;
                        int tmp_mul = 1;
                        for(int i = 0; i <= neg_pos[0]; ++i) tmp_mul *= dp[i];
                        res = max(res, mul/tmp_mul);
                        tmp_mul = 1;
                        for(int i = neg_pos[neg_pos.size()-1]; i < dp.size(); ++i) tmp_mul *= dp[i];
                        res = max(res, mul/tmp_mul);
                    }
                }
                neg_pos.clear();
                dp.clear();
                mul = 1;
            }
            else {
                if(nums[pos] < 0) neg_pos.emplace_back(dp.size());
                dp.emplace_back(nums[pos]);
                mul *= nums[pos];
            }
        }
        return res;
    }
};
// @lc code=end

