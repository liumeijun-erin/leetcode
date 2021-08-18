/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
 */

// @lc code=start
class Solution {
public:
    //solution1:记搜层次遍历
    /*vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(),n = mat[0].size();
        vector<vector<int> > visited(m,vector<int> (n,0));
        queue<pair<int,int> > q;
        vector<int> d{-1,0,1,0,-1};
        for(int i = 0;i < m;++i){
            for(int j = 0;j < n;++j){
               if(mat[i][j] == 0) q.emplace(make_pair(i,j));
            }
        }
        while(!q.empty()){
            int fa = q.front().first;
            int fb = q.front().second;
            q.pop();
            for(int i = 0;i < 4;++i){
                int a = fa + d[i];
                int b = fb + d[i+1];
                if(a >= 0&&a < m&&b >= 0&&b < n&&mat[a][b]&&!visited[a][b]){
                    mat[a][b] = mat[fa][fb] + 1;
                    ++visited[a][b];
                    q.emplace(make_pair(a,b));
                }
            }    
        }
        return mat;
    }*/
    //solution2:参考答案，把复杂限制拆分成右下和做左上两个方向遍历！
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(),n = mat[0].size();
        for(int i = 0;i < m;++i){
            for(int j = 0; j < n;++j){
                if(!mat[i][j]) continue;
                if(!i&&!j) mat[i][j] = 10000;
                else if(!i) mat[i][j] = mat[i][j-1]+1;
                else if(!j) mat[i][j] = mat[i-1][j] + 1;
                else mat[i][j] = min(mat[i][j-1],mat[i-1][j])+1;
                
            }
        }
        for(int i = m - 1;i >= 0;--i){
            for(int j = n - 1; j >= 0;--j){
                if(i == m -1&&j == n -1) continue;
                if(mat[i][j]){
                    if(i == m-1) mat[i][j] = min(mat[i][j],mat[i][j+1] + 1);
                    else if(j == n-1) mat[i][j] = min(mat[i][j],mat[i+1][j] + 1);
                    else  mat[i][j] = min(mat[i][j],min(mat[i][j+1],mat[i+1][j])+1);
                }
            }
        } 
        return mat;
    }
    //[[0,1,1,0,0],[0,1,1,0,0],[0,1,0,0,1],[1,1,1,1,0],[1,0,0,1,0]]
};
// @lc code=end

