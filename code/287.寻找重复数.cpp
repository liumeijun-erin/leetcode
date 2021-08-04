/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        //way1:fail，没有自仔细审题
        //note:accumulate的第三个参数必要，给定类型
        //仔细审题：是至少存在一个重复整数可能多个[2,2,2,2]
        //return accumulate(nums.begin(),nums.end(),- (n-1)*n/2);
        //way2:利用数组下标附加更多信息！
        for(int i = 0;i < nums.size();i++) {
            if(nums[abs(nums[i])] < 0) return abs(nums[i]);
            else nums[abs(nums[i])] *= -1;
        }
        return 0;
    }

};
// @lc code=end

