/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    //控制边界条件不要太混乱
    void backtracking(vector<vector<int> >&ans,vector<int>& res,vector<int>& nums,int target,int pos){
        if(target == 0){
            ans.emplace_back(res);
            return;
        }
        if(pos < nums.size()&&nums[pos] > target) return ;
        int i ,j;
        for(i = pos;i < nums.size();){
            int pre_target = target,k = i;
            while(k < nums.size()&&nums[k] == nums[i]) ++k;
            for(j = i;j < nums.size()&&nums[i] == nums[j];++j){
                res.emplace_back(nums[i]);
                backtracking(ans,res,nums,pre_target-nums[i],k);
                pre_target -= nums[i];
            }
            while(j > i) {
                res.pop_back();
                --j;
            }
            i = k;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> res;
        vector<vector<int> > ans;
        sort(candidates.begin(),candidates.end());
        backtracking(ans,res,candidates,target,0);
        return ans;
    }
};
// @lc code=end

