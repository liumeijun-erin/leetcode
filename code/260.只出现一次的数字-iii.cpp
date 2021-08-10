/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */

// @lc code=start
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        //参考了答案:思路，分组！！！往问题1上构造!!!
        //so在第一遍res的基础上分组：由于res存在说明的是两个数不一样的位，所以一定能分开
        //对于O(n)问题，要想到多次迭代
        int res = 0;
        for(const int& num:nums){
            res ^= num;
        }
        int div = 1;
        while((div&res)==0) div <<= 1;
        int ans1 = 0,ans2 = 0;
        for(const int& num:nums){
            if(num&div) ans1 ^=  num;
            else ans2 ^= num;
        }
        return vector<int> {ans1,ans2};
    }
};
// @lc code=end

