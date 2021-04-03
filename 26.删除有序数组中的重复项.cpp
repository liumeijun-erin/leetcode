/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //tip:two-pointer:no conflict,equidirect 
        //note:keetp array in order
        if(nums.size() == 0){
            return 0;
        }
        int i = 0;
        int j = 1;
        while(j < nums.size()){
            if(nums[j] != nums[i]){
                nums[++i] = nums[j];
            }
            j++;
        }
        return i + 1;
    }
};
// @lc code=end

