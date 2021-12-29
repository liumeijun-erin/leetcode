/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        // s2-空间压缩!!!只用局部a，b存储变量即可
        // dp问题要思考能否空间压缩！
        if (n <= 1) return 1;
        else if (n == 2) return 2;
        int pre_pre = 1,pre = 2;
        for(int i = 3;i <= n; ++i) {
            int res = pre_pre + pre;
            pre_pre = pre;
            pre= res;
        }
        return pre;
        // s1-dp
        // vector<int> res{1,2};
        // for(int i = 2;i < n;i++){
        //     res.emplace_back(res[i-1]+res[i-2]);
        // }
        // return res[n-1];
    }
};
// @lc code=end

