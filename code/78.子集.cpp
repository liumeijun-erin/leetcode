/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    void subsets(vector<vector<int> >& res,vector<int>& nums,int len){
        if(len != 0) subsets(res,nums,len-1);
        int size = res.size();
        for(int i =0;i < size;++i){
            vector<int> tmp = res[i];
            tmp.emplace_back(nums[len]);
            res.emplace_back(tmp);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > res{vector<int> {}};
        subsets(res,nums,nums.size()-1); 
        return res;
    }
};
// @lc code=end

