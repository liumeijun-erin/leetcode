/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    //tip1:排列搜索类问题 定长数组+cnt+-比不断pop/push快很多
    //tip2:可以利用已有结构记录状态不需要新开数组
    void backtracking(vector<vector<int>>& ans, vector<int>& res,int& k,int&cnt,int& n){
        if(cnt == k) {
            ans.emplace_back(res);
            return;
        }
        for(int i = cnt>0?res[cnt-1] + 1:1;i <= n;++i){
            //注意是组合数，要考虑[2,1] [1,2]是否重复计数
            if(n-i < k-cnt-1) break;
            //稍微优化剪枝了一下结果很好
            res[cnt++] = i;
            backtracking(ans,res,k,cnt,n);
            --cnt;
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > ans;
        vector<int> res(k,0);
        int cnt = 0;
        backtracking(ans,res,k,cnt,n);
        return ans;
    }
};
// @lc code=end

