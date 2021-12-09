/*
 * @lc app=leetcode.cn id=794 lang=cpp
 *
 * [794] 有效的井字游戏
 */

// @lc code=start
class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int cnt[8] = {0};
        int cnt_x = 0, cnt_o = 0;
        int pos = 0;
        for (const string& l: board) {
            for (const char& c: l) {
                if (c != ' ') {
                    int row = pos/3;
                    int col = pos%3;
                    int sign = 1;
                    if (c == 'O') {
                        sign = -1;
                        ++cnt_o;
                    }
                    else ++cnt_x;
                    cnt[row] += sign;
                    cnt[col + 3] += sign;
                    if (row == col) cnt[6] += sign;
                    if (row + col == 2) cnt[7] += sign;
                }
                ++pos;
            }
        }
        bool x_full = false, o_full = false;
        int full_col = -1, full_row = -1;
        // for (const int& cnt_tmp: cnt) cout<<cnt_tmp<<" ";
        // cout<<endl;
        for (int i = 0; i < 6; ++i) {
            if (cnt[i] == 3 || cnt[i] == -3) {
                if (cnt[i] == 3) x_full = true;
                else if (cnt[i] == -3) o_full = true;
                if (i < 3) {
                    if (full_row != -1) return false;
                    full_row = i;
                }
                else {
                    if (full_col != -1) return false;
                    full_col = i-3;
                }
            }
        }
        if (cnt[6] == 3 ) x_full = true;
        else if(cnt[6] == -3) o_full = true;
        else cnt[6] = 0;
        if (cnt[7] == 3 ) x_full = true;
        else if(cnt[7] == -3) o_full = true;
        else cnt[7] = 0;
        if (cnt_x != cnt_o &&cnt_x != cnt_o + 1|| x_full && cnt_x == cnt_o ||o_full && cnt_x == cnt_o + 1) return false;
        if (cnt[6] && cnt[7]) {
            if (full_col != -1 && full_col != 1) return false;
            if (full_row != -1 && full_row != 1) return false;
        }
        else if (cnt[6]) {
            if (full_col != -1 && full_col != -1 && full_col != full_row) return false;
        }
        else if (cnt[7]) {
            if (full_col != -1 && full_col != -1 && full_col + full_row != 2) return false;
        }
        return true;
    }
    // 细节：下棋过程结束条件！
    // ["XXX","OOX","OOX"]note1:有多个3连的时候，要判断是否能是最后一步
    // ["XXX","XOO","OO "]note2:细节 X为最终结果的时候不能有X==O!!!
};
// @lc code=end

