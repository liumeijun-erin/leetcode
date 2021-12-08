/*
 * @lc app=leetcode.cn id=689 lang=cpp
 *
 * [689] 三个无重叠子数组的最大和
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<vector<int> > dp(3, vector<int> (nums.size(),0));
        int tmp_sum = accumulate(nums.begin(), nums.begin() + k, 0);
        dp[0][0] = tmp_sum;
        int pre = 0,pos = k;
        while (pos < nums.size() ){
            tmp_sum -= nums[pre++];
            tmp_sum += nums[pos++];
            dp[0][pre] = tmp_sum;
        }
        for (int i = 1; i <= 2; ++i) {
            pos = nums.size() - k*i;
            int max_post = dp[i-1][pos];
            pre = nums.size() - k * (i+1);
            while (pre >= 0) {
                dp[i][pre] = max_post + dp[0][pre];
                --pos;
                --pre; 
                max_post = max(max_post,dp[i-1][pos]);
            }
        }
        vector<int> res;
        pre = -k;
        for (int i = 2; i >= 0; --i) {
            int max_id = pre + k;
            for (int j = pre + k; j < nums.size() ;++j) {
                if(dp[i][j] > dp[i][max_id]) max_id = j;
            }
            pre = max_id;
            res.emplace_back(max_id);
        }
        return res;
        //[7,13,20,19,19,2,10,1,1,19]\n3
    }
};
// @lc code=end

