/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */

// @lc code=start
class Solution {
public:
    //本题参考答案解除
    //参考提示使用位运算，思路是对两次+1次的拓展--原来是消掉两次剩下一次，这里消掉三次剩余一次
    //参考答案:tip1:空间拓展完成同样的功能进行两位使用两个二进制结果数组存储针对3的余数
    //规则是a[i]b[i]:00 01 10对应 原数组之和第i位上的对三的余数
    //tip2:通过ab+x->new ab真值表推出公式
    //tip3:!!!注意这里不是电路不能同时变，先变一个再变另一个！！！
    //推出a = (x^~b)&(a^b)//错，不能同时变
    //推出b = ~a&(x^b)
    //最后结果为b
    int singleNumber(vector<int>& nums) {
        int a = 0,b = 0;
        for(const int& num:nums){
            b = ~a & (num^b);
            a = ~b & (num^a);//！注意这里要用新b重推
        }
        return b;
    }
};
// @lc code=end

