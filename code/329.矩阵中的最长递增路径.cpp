/*
 * @lc app=leetcode.cn id=329 lang=cpp
 *
 * [329] 矩阵中的最长递增路径
 */

// @lc code=start
class Solution {
    vector<int> d = {1,0,-1,0,1};
public:
    void dfs(vector<vector<int>>& matrix,vector<vector<int>>& visited,int x,int y,int& res){
        for(int i = 0;i < 4;++i){
            int next_x = x + d[i];
            int next_y = y + d[i+1];
            if(next_x < 0||next_x>=matrix.size()||next_y < 0||next_y>=matrix[0].size()) continue;
            if(visited[next_x][next_y] >= visited[x][y] + 1) continue;
            if(matrix[next_x][next_y] > matrix[x][y]){
                visited[next_x][next_y] = visited[x][y] + 1;
                res = max(visited[next_x][next_y],res);
                dfs(matrix,visited,next_x,next_y,res);
            }
        }
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(),n = matrix[0].size();
        int res = 1;
        vector<vector<int> > visited(m,vector<int> (n,0));
        for(int i = 0;i < m;++i){
            for(int j = 0;j < n;++j){
                bool localmin = true;
                for(int k = 0;k < 4;++k){
                    if(i + d[k] < 0||i+d[k] >= m||j + d[k+1] < 0||j + d[k+1] >= n) continue;
                    if(matrix[i+d[k]][j+d[k+1]] < matrix[i][j]){
                        localmin= false;
                        break;
                    }
                }
                if(localmin) {
                    visited[i][j] = 1;
                    dfs(matrix,visited,i,j,res);
                }
            }
        }
        return res;
    }
    //[[0,1,2,3,4,5,6,7,8,9],[19,18,17,16,15,14,13,12,11,10],[20,21,22,23,24,25,26,27,28,29],[39,38,37,36,35,34,33,32,31,30],[40,41,42,43,44,45,46,47,48,49],[59,58,57,56,55,54,53,52,51,50],[60,61,62,63,64,65,66,67,68,69],[79,78,77,76,75,74,73,72,71,70],[80,81,82,83,84,85,86,87,88,89],[99,98,97,96,95,94,93,92,91,90],[100,101,102,103,104,105,106,107,108,109],[119,118,117,116,115,114,113,112,111,110],[120,121,122,123,124,125,126,127,128,129],[139,138,137,136,135,134,133,132,131,130],[0,0,0,0,0,0,0,0,0,0]]
};
// @lc code=end

