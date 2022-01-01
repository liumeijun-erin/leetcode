/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    //  本题不会，参考答案
    //  核心:模拟实际排序过程，利用从后侧不断向前排序过程找到要改变的位，且利用后面已经排成从大到小的规律！！！！
    //  思想： 从两个区间内找到一对数，i < j。用j替换i之后后面的的数从小到大排列
    //  要求i尽量靠右，且j尽可能小
    //  策略：从右侧往前遍历i找到第一个num[i] < num[i+1]的 这是必须进位的条件
    //  然后从右往左遍历j：利用右侧已经有序的情况将选中大于i的最小的j
    // 注意i可以为-1 [321]情况
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-2;
        while (i >= 0 && nums[i+1] <= nums[i]) --i;
        if (i >= 0) {
            int j = nums.size()-1;
            while (j > i&& nums[j] <= nums[i]) --j;
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
        //[1,3,2]
        //[2,3,1]
    }
};
// @lc code=end

