/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        vector<int> num(n+1,-1);
        int i ,j = 0;
        for(int i = 1;i <= n;i++){
            if(j == i*i) num[j] = 1;
            num
        }
        return num[n];
    }
};
// @lc code=end

