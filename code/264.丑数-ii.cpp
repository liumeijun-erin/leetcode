/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        // 参考答案：三指针
        vector<int> dp(n);
        dp[0] = 1;
        int i = 0, j = 0, k = 0;
        int num1 = 2, num2 = 3, num3 = 5;
        for (int pos = 1; pos < n; ++pos) {
            dp[pos] = min(num1, min(num2, num3));
            if (dp[pos] == num1) num1=dp[++i]*2;
            if (dp[pos] == num2) num2=dp[++j]*3;
            if (dp[pos] == num3) num3=dp[++k]*5;
        }
        return dp.back();
        //solution2
        // priority_queue<int,vector<int>,greater<int> > q;
        // unordered_set<int> s;
        // s.emplace(1);
        // q.emplace(1);
        // int res = -1;
        // int MaxNum = 2147483647;
        // while(n--) {
        //     res = q.top();
        //     q.pop();
        //     if (res <= MaxNum/2&&!s.count(res*2)) {
        //         q.emplace(res*2);
        //         s.emplace(res*2);
        //     }
        //     if (res <= MaxNum/3&&!s.count(res*3)) {
        //         q.emplace(res*3);
        //         s.emplace(res*3);
        //     }
        //     if (res <= MaxNum/5&&!s.count(res*5)) {
        //         q.emplace(res*5);
        //         s.emplace(res*5);
        //     }
        // }
        // return res;
    }
};
// @lc code=end

