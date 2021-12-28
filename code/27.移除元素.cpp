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
        // 逆向双指针 vs leetcode26同向
        int i = 0, j = nums.size()-1;
        while (i <= j) {
            while (i <= j && nums[i] != val) ++i;
            while (i <= j && nums[j] == val) --j;
            if(i < j) nums[i++] = nums[j--];
        }
        return i;
    }
};
// @lc code=end

