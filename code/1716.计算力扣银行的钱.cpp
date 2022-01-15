/*
 * @lc app=leetcode.cn id=1716 lang=cpp
 *
 * [1716] 计算力扣银行的钱
 */

// @lc code=start
class Solution {
public:
    // 1 2 3 4 5 6 7  -- 28
    // 2 3 4 -- 9
    int totalMoney(int n) {
        int week = n/7;
        int sum = (4 + week + 3) * 7 * week / 2;
        int day = n%7;
        sum += (week + 1 + week + day) * day / 2;
        return sum;
    }
};
// @lc code=end

