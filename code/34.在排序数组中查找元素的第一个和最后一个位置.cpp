/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //左闭右开区间
        vector<int> res(2,-1);
        if(nums.empty()) return res;
        int left = 0,right = nums.size();
        while(left <= right- 1){
            int mid = left + (right - left)/2;
            if(nums[mid] >= target){
                right = mid;
            } 
            else{
                left = mid + 1;
            }
        }
        if(left < nums.size()&&nums[left] == target) res[0] = left;
        else return res;
        left = 0;
        right = nums.size();
        while(left <= right- 1){
            int mid = left + (right - left)/2;
            if(nums[mid] <= target){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        if(left - 1< nums.size()&&nums[left-1] == target) res[1] = left-1;
        else return vector<int> {-1,-1};
        return res;
    }
};
// @lc code=end

