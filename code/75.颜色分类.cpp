/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count[3] = {0};
        for(const int& n:nums){
            ++count[n];
        }
        fill(nums.begin(),nums.begin() + count[0] ,0);
        fill(nums.begin() + count[0],nums.begin() + count[0] + count[1],1);
        fill(nums.begin() + count[0] + count[1],nums.end(),2);
    }
};
// @lc code=end

