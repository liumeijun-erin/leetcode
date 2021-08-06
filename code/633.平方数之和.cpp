/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 */

// @lc code=start
class Solution {
public:
    bool judgeSquareSum(int c) {
        //这种在有序上找两个值的，要能联想到双指针！
        double i = 0,j = int(sqrt(c));
        while(i <= j){
            if(i*i+j*j == c) return true;
            if(i*i + j*j < c) ++i;
            else if(i*i + j*j > c) --j;
        }
        return false;
    }
};
// @lc code=end

