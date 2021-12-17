/*
 * @lc app=leetcode.cn id=1518 lang=cpp
 *
 * [1518] 换酒问题
 */

// @lc code=start
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        if (numBottles >= numExchange) numBottles += (numBottles - numExchange) / (numExchange - 1 ) + 1;
        return numBottles;
    }
};
// @lc code=end

