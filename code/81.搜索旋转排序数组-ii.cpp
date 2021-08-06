/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        //way1:情况分的很具体，结果也不错
        if(target == nums[0]) return true;
        int left = 0,right = nums.size()-1;
        while(left <= right&&nums[left] == nums[0]) ++left;
        while(left <= right&&nums[right] == nums[0]) --right;
        //这里是将前后端点值一起处理完，答案中使用不提前处理，每次nums[start] == nums[mid]的时候++start,也可以规避
        ++right;
        bool upper = target > nums[0];
        while(left < right){
            int mid = left + (right - left)/2;
            if(upper&&nums[mid] > nums[0]||!upper&&nums[mid] < nums[0]){
                if(target == nums[mid]) return true;
                if(target < nums[mid]) right = mid;
                else left = mid + 1;
            }
            else if(upper&&nums[mid] < nums[0]) right = mid;
            else left = mid + 1;
        }
        return false;
    }
};
// @lc code=end

