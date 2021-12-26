/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        // 考虑重复边界值：[3,1,3], [3,3,1,3] \ [1,2,1] [0,1,1,0]
        int left = 0,right = nums.size()-1;
        while(left < right && nums[left] == nums[0]) ++left;
        while(left < right && nums[right] == nums[0]) --right;
        if(nums[right]>=nums[0]) return nums[0];
        ++right;
        while(left < right){
            int mid = left + (right - left)/2;
            if(nums[mid] > nums[0]) left = mid + 1;
            else{
                if(nums[mid - 1] <= nums[mid]) right = mid;
                else return nums[mid];
            }
        }
        return nums[left];
    }
};
// @lc code=end

