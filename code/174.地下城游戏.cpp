/*
 * @lc app=leetcode.cn id=174 lang=cpp
 *
 * [174] 地下城游戏
 */

// @lc code=start
class Solution {
public:
    //大致思路有了，但是参考答案才理清
    //遍历方向很重要！！！！：左上到右下既希望path和尽可能大，又要过程中尽可能小没法割舍；
    //而从右下到左上只要保证能到达的最小即可过程中已经走完减去完！！！
    //注意此题并非获取最后的最大点数，而是要规避过程中的最小值！
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m  = dungeon.size(),n = dungeon[0].size();
        vector<vector<int> > dp(m+1,vector<int> (n+1));
        //注意与1的关系是精髓!!!!最后是1一开始也得是1
        dp[m-1][n-1] = 1;
        for(int i = m-1;i >= 0;--i){
            for(int j = n-1;j >= 0;--j){
                //这里的逻辑以及和1的关系也参考答案划分！！！
                if(i < m-1&&j < n-1) dp[i][j] = min(dp[i+1][j],dp[i][j+1]);
                else if(i < m-1) dp[i][j] = dp[i+1][j];
                else if(j < n-1) dp[i][j] = dp[i][j+1];
                dp[i][j] = max(dp[i][j]-dungeon[i][j],1);//!!!
            }
        }
        return dp[0][0];
    }
};
// @lc code=end

