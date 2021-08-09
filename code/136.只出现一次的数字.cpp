/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //不涉及到进位，对于每一位来说置零和置1的次数固定
        int res = 0;
        for(const int& num:nums){
            cout<<res<<" "<<num<<" ";
            res ^= num;
            cout<<res<<endl;
        }
        return res;
    }
};
// @lc code=end

