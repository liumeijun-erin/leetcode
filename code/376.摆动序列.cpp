/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        if(nums.size() == 2){
            if(nums[0] == nums[1]) return 0;
            else return 2;
        }
        int cnt = 0;
        int i = 1;
        while(nums[i] == num[i-1]) ++i;
        bool pos = (nums[i] > nums[i-1])?true:false;
        for(;i < nums.size();++i){
            if(nums[i] - )
        }
    }
};
// @lc code=end

