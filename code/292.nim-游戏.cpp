/*
 * @lc app=leetcode.cn id=292 lang=cpp
 *
 * [292] Nim 游戏
 */

// @lc code=start
class Solution {
public:
    bool canWinNim(int n) {
        //思路：-1-2-3有一个输的就算赢，列出来即可
        return n%4;
    }
};
// @lc code=end

