/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<vector<int>>& res,vector<int>& candidates,int pos,int& target,vector<int>& path){
        int num = candidates[pos],target_tmp = target,cnt = 0;
        if(pos+1<candidates.size()) dfs(res,candidates,pos+1,target,path);
        while(target>0){
            target -= num;
            path.emplace_back(num);
            if(target == 0) {res.emplace_back(path);}
            if(pos+1<candidates.size()) dfs(res,candidates,pos+1,target,path);
            cnt += 1;
        }
        target = target_tmp;
        while(cnt--) path.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        vector<int> path;
        dfs(res,candidates,0,target,path);
        return res;
    }
};
// @lc code=end

