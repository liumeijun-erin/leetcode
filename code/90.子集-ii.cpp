/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
public:
    void bp(vector<vector<int> >& res,vector<int> &cnt,int pos){
        if(pos != 0) bp(res,cnt,pos-1);
        int cnt_p = cnt[pos];
        while(cnt_p--){
            int len = res.size();
            for(int i = 0;i < len;++i){
                vector<int> tmp = res[i];
                res.emplace_back(tmp.emplace_back(pos-10));
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> cnt(21);
        vector<vector<int> > res{vector<int> {}};
        for(const int& num:nums){
            ++cnt[num+10];
        }
        bp(res,cnt,20);
        return res;
    }
};
// @lc code=end

