/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //tip:two-pointer front vs end
        //avoid unnecessary moves compared to leetcode26
        int i = 0;
        int j = nums.size() - 1;
        while(i <= j){
            if(nums[i] == val){
                nums[i] = nums[j];
                j--;
            }
            else{
                i++;
            }
        }
        return j + 1;
    }
};
// @lc code=end

