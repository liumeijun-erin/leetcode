/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //solution1：设置了27个set 慢且大
        //solution2：由于0-9key简单，改成vector 46/16
        //solution3:还是慢，改成int--格式固定且初始化为0且操作简单仅读取
        //note：同样的思路int性能提高好多！！！96/66！
        int cnt_line[9][9] = {0};
        int cnt_col[9][9] = {0};
        int cnt_square[3][3][9] = {0};
        for(int i = 0;i < 9;++i){
            for(int j = 0;j < 9;++j){
                if(board[i][j]=='.') continue;
                int num = board[i][j] - '1';
                if(cnt_line[i][num]||cnt_col[num][j]||cnt_square[i/3][j/3][num]) return false;
                cnt_line[i][num]=1;
                cnt_col[num][j]=1;
                cnt_square[i/3][j/3][num]=1;
            }
        }
        return true;
    }
};
// @lc code=end

