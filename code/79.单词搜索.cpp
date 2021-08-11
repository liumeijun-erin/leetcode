/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
    vector<int> directions{-1,0,1,0,-1};
public:
    void backtracking(vector<vector<char>>& board, string& word,int &i,int &j,int k,bool& exists){
        //可在原数组上表示状态也可以加一个visited数组
        if(k == word.size()-1){
            exists = true;
            return;
        }
        board[i][j] = ' ';
        int x,y;
        for(int n = 0;n < 4;++n){
            x = i + directions[n];
            y = j + directions[n+1];
            if(x>=0&&x<board.size()&&y>=0&&y<board[0].size()&&board[x][y] == word[k+1]) backtracking(board,word,x,y,k+1,exists);
            if(exists) break;
        }
        board[i][j] = word[k];
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool exists = false;
        for(int i = 0;i < board.size();++i){
            for(int j = 0;j < board[0].size();++j){
                if(board[i][j] ==word[0]) backtracking(board,word,i,j,0,exists);
            }
        }
        return exists;
    }
};
// @lc code=end

