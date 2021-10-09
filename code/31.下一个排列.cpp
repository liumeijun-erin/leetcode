/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int reverse_left = 0;
        for(int i = nums.size()-1;i > 0;--i){
            if(nums[i-1] < nums[i]){
                for(int j = nums.size()-1;j >= i;--j){
                    if(nums[j] > nums[i-1]){
                        swap(nums[j],nums[i-1]);
                        reverse_left = i;
                        break;
                    }
                }
                break;
            }
        }
        reverse(nums.begin()+reverse_left,nums.end());
        //[1,3,2]
        //[2,3,1]
    }
};
// @lc code=end

