/*
 * @lc app=leetcode.cn id=540 lang=cpp
 *
 * [540] 有序数组中的单一元素
 */

// @lc code=start
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0,right = nums.size()-1;
        while(left < right){
            int mid = left + (right - left)/2;
            if(mid >= 1&&nums[mid] == nums[mid - 1]){
                if((mid - left + 1)%2) right = mid;
                else left = mid+1;
            }
            else if(mid + 1< nums.size()&&nums[mid] == nums[mid + 1]){
                if((mid - left) % 2) right = mid - 1;
                else left = mid;
            }
            else return nums[mid];
        }
        return nums[left];
    }
};
// @lc code=end

