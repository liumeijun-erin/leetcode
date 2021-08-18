/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        //动态规划自顶向上
        vector<int> num(n+1);
        num[0] = 0;
        int i ,j = 0;
        for(int i = 1;i <= n;++i){
            num[i] = i;
            for(int j = 2;j <= sqrt(i);++j){
                num[i] = min(num[i - j*j]+1,num[i]);
            }
        }
        return num[n];
    }
};
// @lc code=end

