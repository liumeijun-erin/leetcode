/*
 * @lc app=leetcode.cn id=665 lang=cpp
 *
 * [665] 非递减数列
 */

// @lc code=start
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0;
        for(int i = 1;i < nums.size();i++){
            if(nums[i] < nums[i - 1]){
                ++cnt;
                if(i < nums.size() - 1 && i >= 2 && nums[i+1] < nums[i - 1]  && nums[i-2] > nums[i]){
                    ++cnt;
                    break;
                }
            }
        }
        return cnt <= 1;
    }
};
// @lc code=end

