/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */

// @lc code=start
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt(n);
        vector<int> res;
        for(int i = 0;i < n;i++){
            cnt[nums[i]-1]++;
        }
        for(int i = 0;i < n;i++){
            if(!cnt[i]) res.push_back(i+1);
        }
        return res;
    }
};
// @lc code=end

