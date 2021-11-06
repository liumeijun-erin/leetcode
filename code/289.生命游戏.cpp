/*
 * @lc app=leetcode.cn id=289 lang=cpp
 *
 * [289] 生命游戏
 */

// @lc code=start
class Solution {
public:
    void help(vector<vector<int> >& board,int& i,int& j,int &cnt){
        if(i - 1 >= 0){
            if(j - 1 >= 0&&board[i-1][j-1]) ++cnt;
            if(board[i-1][j]) ++cnt;
            if(j + 1 < board[0].size() && board[i-1][j+1]) ++cnt;
        }
        if(j-1 >= 0 && board[i][j-1]) ++cnt;
        if(j+1 < board[0].size() && board[i][j+1]) ++cnt;
        if(i + 1 < board.size()){
            if(j - 1 >= 0&&board[i+1][j-1]) ++cnt;
            if(board[i+1][j]) ++cnt;
            if(j + 1 < board[0].size() && board[i+1][j+1]) ++cnt;
        }
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int> > new_board(board);
        int m = board.size(),n = board[0].size(),cnt;
        for(int i = 0;i < m;++i){
            for(int j = 0;j < n;++j){
                cnt = 0;
                help(new_board,i,j,cnt);
                if(board[i][j]&&(cnt<2||cnt>3)||!board[i][j]&&cnt == 3) {
                    board[i][j] = 1- board[i][j];
                }
            }
        }
    }
};
// @lc code=end

