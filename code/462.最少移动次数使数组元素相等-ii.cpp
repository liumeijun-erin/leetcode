/*
 * @lc app=leetcode.cn id=462 lang=cpp
 *
 * [462] 最少移动次数使数组元素相等 II
 */

// @lc code=start
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        //tip:先分析注意不能用简单的均值，因为正负不能抵消
        //wrong answer,不能拿过来就做!
        /*int sum = accumulate(nums.begin(),nums.end(),0);
        int avg = round(sum*1.0/nums.size());
        sum = 0;
        for(const int & num:nums){
            sum +=  abs(num - avg);
        }*/
        sort(nums.begin(),nums.end());
        vector<long long> left(nums.size());
        vector<long long> right(nums.size());
        for(int i = 1;i < nums.size();++i){
            left[i] = left[i-1] + (nums[i] - nums[i-1])*i;
        }
        long long steps = left[nums.size()-1];
        for(int i = nums.size()-2;i>= 0;--i){
            right[i] = right[i+1] + (nums[i+1] - nums[i])*(nums.size() -1 -i);
            if(right[i] > steps) continue;
            steps = min(steps,left[i] + right[i]);
        }
        return steps;
    }
};
// @lc code=end

