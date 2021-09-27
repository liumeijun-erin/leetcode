/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0,right = nums.size()-1;
        while(left < right){
            if(nums[left] <= nums[right]) return nums[left];
            int mid = (right-left)/2 + left;
            if(nums[mid]< nums[left]) right = mid;
            else left = mid + 1;
        }
        //[3,1,2]
        return nums[left];
    }
};
// @lc code=end

