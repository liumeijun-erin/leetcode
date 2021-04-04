/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //tip:two-pointer
        //use nums[j] > nums[i - 2] instead of using var count
        if(nums.size() <= 2){
            return nums.size();
        }
        int i = 2;
        for(int j = 2;j < nums.size();j++){
            if(nums[j] > nums[i - 2]){
                nums[i++] = nums[j];
            }
        }
        return i;
    }
};

