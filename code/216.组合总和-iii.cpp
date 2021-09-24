/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
public:
    //todo:bp may be faster
    void dfs(vector<vector<int> >& res,vector<int>& ans,int k,int n,int pos){
        if(pos > n||k<=0) return;
        if(pos == n&&k==1){
            ans.emplace_back(pos);
            res.emplace_back(ans);
            ans.pop_back();
        }
        else if(pos <= 8){
            dfs(res,ans,k,n,pos+1);
            ans.emplace_back(pos);
            dfs(res,ans,k-1,n-pos,pos+1);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > res;
        vector<int> ans;
        dfs(res,ans,k,n,1);
        return res;
    }
};
// @lc code=end

