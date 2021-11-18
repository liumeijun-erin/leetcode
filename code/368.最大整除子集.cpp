/*
 * @lc app=leetcode.cn id=368 lang=cpp
 *
 * [368] 最大整除子集
 */

// @lc code=start
class Solution {
public:
    //参考答案：排序+dp dfs太过分，dp两层遍历可以接受1000*1000
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int len = 1,last_pos = 0;
        sort(nums.begin(),nums.end());
        vector<int> dp(nums.size(),1);
        vector<int> trace_back(nums.size(),-1);
        for(int i = 0; i < nums.size(); ++i) {
            for(int j = i-1; j >= 0; --j) {
                if(nums[i]%nums[j] == 0) {
                    //cout<<nums[j]<<" "<<nums[i]<<endl;
                    if(dp[j] + 1 > dp[i]) {
                        trace_back[i] = j;
                        dp[i] = dp[j] + 1;
                        if(len < dp[i]) {
                            last_pos = i;
                            len = dp[i];
                        }
                    }
                }
            }
        }
        vector<int> res;
        for(int i = last_pos;i != -1; i = trace_back[i]) {
            res.emplace_back(nums[i]);
        }
        return res;
    }
};
// @lc code=end

