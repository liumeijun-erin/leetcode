/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
public:
    void backtracking(vector<vector<string> >& ans,vector<int>& res,vector<int>& visited,int k,int& n){
        if(k == n){
            vector<string> res_s;
            for(int i = 0;i < n;++i){
                string s = "";
                for(int j = 0;j < n;++j){
                    if(j == res[i]) s += 'Q';
                    else s += '.'; 
                }
                res_s.emplace_back(s);
            }
            ans.emplace_back(res_s);
            return;
        }
        for(int i = 0;i < n;++i){
            if(visited[i]) continue;
            int j = 0;
            for(;j < k;j++){
                if(abs(k - j) == abs(res[j] - i)) break;
            }
            if(j < k) continue;
            visited[i] = 1;
            res[k] = i;
            backtracking(ans,res,visited,k+1,n);
            res[k] = -1;
            visited[i] = 0;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<int> res(n,-1);
        vector<int> visited(n,0);
        vector<vector<string> > ans;
        backtracking(ans,res,visited,0,n);
        return ans;
    }
};
// @lc code=end

