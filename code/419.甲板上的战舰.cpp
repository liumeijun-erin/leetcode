/*
 * @lc app=leetcode.cn id=419 lang=cpp
 *
 * [419] 甲板上的战舰
 */

// @lc code=start
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int res = 0;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == 'X') {
                    ++res;
                    board[i][j] = '.';
                    int tmp = j-1;
                    while (tmp >= 0 && board[i][tmp] == 'X') board[i][tmp--] = '.';
                    tmp = j+1;
                    while (tmp < board[0].size() && board[i][tmp] == 'X') board[i][tmp++] = '.';
                    tmp = i-1;
                    while (tmp >= 0 && board[tmp][j] == 'X') board[tmp--][j] = '.';
                    tmp = i+1;
                    while (tmp < board.size() && board[tmp][j] == 'X') board[tmp++][j] = '.';
                }

            }
        }
        return res;
    }
};
// @lc code=end

