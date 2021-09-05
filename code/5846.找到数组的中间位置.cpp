/*
 * @lc app=leetcode.cn id=5846 lang=cpp
 *
 * [5846] 找到数组的中间位置
 */

// @lc code=start
class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;
        for(int i = 1;i < n;++i) nums[i] += nums[i-1];
        if(nums[n-1]-nums[0] == 0) return 0;
        for(int i = 1;i < n;++i){
            if(nums[i-1] == nums[n-1]-nums[i]) return i;
        }
        return -1;
        
    }
};

// @lc code=end

