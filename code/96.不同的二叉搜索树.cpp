/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
public:
    int help(vector<int>& ms, int n) {
        if(ms[n]) return ms[n];
        for(int i = 1;i <= n; ++i) {
            ms[n] += help(ms, i-1) * help(ms, n-i);
        }
        return ms[n];
    }
    int numTrees(int n) {
        vector<int> ms(n+1,0);
        ms[0] = 1;
        ms[1] = 1;
        return help(ms, n);
    }
};
// @lc code=end

