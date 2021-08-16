/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        //todo:空间压缩，只用局部a，b存储变量即可
        vector<int> res{1,2};
        for(int i = 2;i < n;i++){
            res.emplace_back(res[i-1]+res[i-2]);
        }
        return res[n-1];
    }
};
// @lc code=end

