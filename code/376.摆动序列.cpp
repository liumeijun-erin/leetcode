/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int i = 1;
        while(i<nums.size()&&nums[i] == nums[i-1]) ++i;
        if(i == nums.size()) return 1;
        int cnt = 2;
        bool pos = nums[i] > nums[i-1];
        for(++i;i < nums.size();++i){
            if(nums[i] - nums[i-1]>0&&!pos||nums[i] - nums[i-1]<0&&pos) {
                ++cnt;
                pos = !pos;
            } 
        }
        return cnt;
    }
};
//[0,0]
// @lc code=end

