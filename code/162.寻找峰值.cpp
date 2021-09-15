/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
class Solution {
public:
    
    int findPeakElement(vector<int>& nums) {
        if(nums.size()<=1) return 0;
        int left = 0,right= nums.size()-1;
        while(left<right){
            int mid = (right-left)/2 + left;
            if(mid==0||nums[mid-1]<nums[mid]){
                if(mid==nums.size()-1||nums[mid+1]<nums[mid]) return mid;
                left = mid+1;
            }
            else right = mid-1;
        }
        return left;
        //[1]
        //[1,2,3,1]
        //[1,2]
        //[1,2,1,3,5,6,4]
        //[6,5,4,3,2,3,2]
    }
};
// @lc code=end

