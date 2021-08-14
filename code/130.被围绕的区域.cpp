/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
class Solution {
    vector<int> d{-1,0,1,0,-1};
public:
    void dfs(vector<vector<char> > &board,vector<vector<bool> >& visited,int x,int y){
        visited[x][y] = true;
        for(int i = 0;i < 4;++i){
            int a = x + d[i];
            int b = y + d[i+1];
            if(a>0&&a<board.size()&&b>0&&b<board[0].size()&&board[a][b] == 'O'&&!visited[a][b]){
                dfs(board,visited,a,b);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size(),n = board[0].size();
        vector<vector<bool> > visited(m,vector<bool> (n,false));
        int i,j;
        for(i = 0;i < m;++i){
            if(board[i][0] == 'O') dfs(board,visited,i,0);
            if(board[i][n-1] == 'O') dfs(board,visited,i,n-1);
        }
        for(i = 1;i < n-1;++i){
            if(board[0][i] == 'O') dfs(board,visited,0,i);
            if(board[m-1][i] == 'O') dfs(board,visited,m-1,i);
        }
        for(i = 0;i < m;++i){
            for(j = 0;j < n;++j){
                if(board[i][j] == 'O'&&!visited[i][j]) board[i][j] = 'X';
            }
        }
    }
};
// @lc code=end

