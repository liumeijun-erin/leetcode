/*
 * @lc app=leetcode.cn id=932 lang=cpp
 *
 * [932] 漂亮数组
 */

// @lc code=start
class Solution {
public:
    vector<vector<int> > dp;
    Solution(){
        dp.resize(1001);
        dp[1] = {1};
    }
    //参考答案：先从问题根本思考性质!!!：要使xy平均数为int，xy应该是偶偶/奇奇
    //所以可以划分为偶、奇序列
    vector<int> beautifulArray(int n) {
        if(!dp[n].empty()) return dp[n];
        int mid = n/2;
        vector<int> res;
        for(const int & i:beautifulArray(mid)){
            res.push_back(2*i);
        }
        if(n%2){
            for(const int & i:beautifulArray(mid + 1)){
                res.push_back(2*i-1);
            }
        }
        else{
            for(const int & i:dp[mid]) {
                res.push_back(2*i-1);
            }
        }
        dp[n] = res;
        return res;
    }
};
// @lc code=end

