/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    //solution1:使用hash+unordered_set慢
    //solution2:思考回溯本质，在swap的时候改变
    //solution3:todo先对数组排序然后检查n不与之前相同
    void backtracking(vector<vector<int> >& ans,vector<int> &nums,/*vector<long long> &hash,unordered_set<long long> &s,*/int pos){
        if(pos == nums.size() - 1) {
            /*long long hashnum = 0;
            for(int i = 0;i < nums.size();++i){
                hashnum += (nums[i]+10)*hash[i];
            }
            if(!s.count(hashnum)){
                ans.emplace_back(nums);
                s.insert(hashnum);
            }
            return;*/
            ans.emplace_back(nums);
            return ;
        }
        vector<int> hash(21,1);
        for(int i = pos;i < nums.size();i++){
            if(hash[nums[i] + 10]){
                hash[nums[i]+10] = 0;
                swap(nums[i],nums[pos]);
                backtracking(ans,nums/*,hash,s*/,pos + 1);
                swap(nums[i],nums[pos]);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        //unordered_set<long long> s;
        vector<vector<int> > ans;
        //vector<long long> hash(nums.size(),1);
        //for(int i = nums.size() - 2;i >= 0;--i) hash[i] = hash[i+1] * 20;
        backtracking(ans,nums,/*hash,s,*/0);
        return ans;
    }
};
// @lc code=end

