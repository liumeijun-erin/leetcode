
/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0,right = nums.size()-1;
        while(left <= right){
            int mid = (right-left)/2 + left;
            if(nums[mid]< target) {
                if(nums[mid] < nums[left]&&target >= nums[left]) right = mid-1;
                else left = mid+1;
            }
            else if(nums[mid] > target){
                if(nums[mid] > nums[right]&&target <= nums[right]) left = mid+1;
                else right = mid-1;
            }
            else return mid;
        }
        //[5,1,3]\n-1
        return -1;
    }
};
// @lc code=end

