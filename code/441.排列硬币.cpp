/*
 * @lc app=leetcode.cn id=441 lang=cpp
 *
 * [441] 排列硬币
 */

// @lc code=start
class Solution {
public:
    int arrangeCoins(int n) {
        int cnt = 1;
        while(n >= cnt){
            n -= cnt++;
        }
        return cnt - 1;
    }
};
// @lc code=end

