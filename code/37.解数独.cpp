/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
class Solution {
   
public:
    //todo：直接在board上改，不用num，但是现在存在小bug
    void dfs(vector<vector<char> >& board,int pos,vector<vector<int> >& square,vector<vector<int> > & row,vector<vector<int> >& col,vector<pair<int,int> >& vacancy,vector<int>& num){
        if(pos == vacancy.size()) {
            for(int i = 0;i < vacancy.size();++i){
                board[vacancy[i].first][vacancy[i].second] = '1'+ num[i];
            }
            return ;
        }
        int x = vacancy[pos].first;
        int y = vacancy[pos].second;
        for(int i = 0;i < 9;++i){
            if(!square[(x/3)*3+y/3][i]&&!row[x][i]&&!col[y][i]){
                num[pos] = i;
                //board[x][y] = i + '1';
                square[(x/3)*3+y/3][i] = 1;
                row[x][i] = 1;
                col[y][i] = 1;
                dfs(board,pos+1,square,row,col,vacancy,num);
                square[(x/3)*3+y/3][i] = 0;
                row[x][i] = 0;
                col[y][i] = 0;
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int> > square(9,vector<int> (9,0));
        vector<vector<int> > col(9,vector<int> (9,0));
        vector<vector<int> > row(9,vector<int> (9,0));
        vector<pair<int,int> > vacancy;
        vector<int> num;
        int i,j,n;
        for(i = 0;i < 9;++i){
            for(j = 0;j < 9;++j){
                if(board[i][j] != '.'){
                    n = board[i][j] - '1';
                    row[i][n]= 1;
                    col[j][n]= 1;
                    square[(i/3)*3+j/3][n] = 1;
                } 
                else{
                    vacancy.emplace_back(make_pair(i,j));
                    num.emplace_back(-1);
                }
            }
        }
        dfs(board,0,square,row,col,vacancy,num);
        return ;
    }
};
// @lc code=end

