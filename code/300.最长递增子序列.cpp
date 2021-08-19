/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        /*int max_len = 1;
        vector<int> len(nums.size(),1);
        for(int i = 0;i < nums.size();++i){
            for(int j = 0;j < i;j++){
                if(nums[i] > nums[j]){
                    len[i] = max(len[i],len[j] + 1); 
                }
            }
            max_len = max(max_len,len[i]);
        }
        return max_len;*/
        //优化解！！！维护一个有序数组
        //参考答案二分查找
        //存储长度已知子串的数值最小的
        //lower_bound本质二分查找！dp不一定是答案，但是已经存在这个长度的解之后把小的换进去有助于得到更大解且能保证这个长度的解一定存在
        vector<int> dp;
        dp.push_back(nums[0]);
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (dp.back() < nums[i]) {
                dp.push_back(nums[i]);
            } else {
                auto itr = lower_bound(dp.begin(), dp.end(), nums[i]);
                *itr = nums[i];
            }
        }
        return dp.size();
    }
};
// @lc code=end

