/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
    vector<int> d{-1,0,1,0,-1};
public:
    /*pair<int,int> find(vector<vector<pair<int,int> > >& fid,int x,int y){
        pair<int,int> p = make_pair(x,y);
        while(fid[p.first][p.second]!=p){
            p = fid[p.first][p.second];
        }
        fid[x][y]=p;
        return p;
    }*/
    void dfs(vector<vector<char>>& grid,int i,int j){
        if(i < 0||i>=grid.size()||j<0||j>=grid[0].size()) return;
        if(grid[i][j]=='1'){
            grid[i][j] = '0';
            for(int k = 0;k < 4;++k){
                dfs(grid,i+d[k],j+d[k+1]);
            }
        } 
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(),n = grid[0].size(),cnt = 0;
        //vector<int> d{-1,0,1,0,-1};
        //solution1:dfs表现不好
        //改进：不用pair用n*x+y没区别
        /*for(int i = 0;i < m;++i){
            for(int j = 0;j < n;++j){
                if(grid[i][j] == '1'){
                    ++cnt;
                    queue<int > q;
                    q.emplace(301*i+j);
                    grid[i][j]='0';
                    while(!q.empty()){
                        int front = q.front();
                        q.pop();
                        for(int k = 1;k < 5;++k){
                            int i_new = front/301 + d[k-1],j_new = front%301 + d[k];
                            if(i_new>=0&&i_new<m&&j_new>=0&&j_new<n&&grid[i_new][j_new]=='1'){
                                grid[i_new][j_new] = '0';
                                q.emplace(301*i_new+j_new);
                            }
                        }
                    }
                }
            }
        }
        return cnt;*/
        //solution1.5递归试试，竟然比queue好
        for(int i = 0;i < m;++i){
            for(int j = 0;j < n;++j){
                if(grid[i][j] == '1'){
                    ++cnt;
                    dfs(grid,i,j);
                }
            }
        }
        return cnt;
        //solution2:
        //参考答案使用并查集优化，但是性能没有提高
        /*vector<vector<pair<int,int> > > fid(m,vector<pair<int,int> >(n));
        for(int i = 0;i < m;++i){
            for(int j = 0;j < n;++j){
                if(grid[i][j] == '1'){
                    fid[i][j] = make_pair(i,j);
                    if(i>0&&grid[i-1][j]=='1') fid[i][j] = find(fid,i-1,j);
                    if(j>0&&grid[i][j-1]=='1') fid[find(fid,i,j-1).first][find(fid,i,j-1).second] = find(fid,i,j);   
                }
            }
        }
        for(int i = 0;i < m;++i){
            for(int j = 0;j < n;++j){
                if(grid[i][j] == '1'&&find(fid,i,j) == make_pair(i,j)) ++cnt;
            }
        }
        //[   ["1","1","0","0","0"],   ["1","1","0","0","0"],   ["0","0","1","0","0"],   ["0","0","0","1","1"] ]
        //[["1","1","1"],["0","1","0"],["1","1","1"]]
        return cnt;*/
    }
};
// @lc code=end

