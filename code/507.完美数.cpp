/*
 * @lc app=leetcode.cn id=507 lang=cpp
 *
 * [507] 完美数
 */

// @lc code=start
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 1) return false;
        int res = 1;
        for (int i = 2; i <= num/2; ++i) {
            if (num%i == 0) {
                res += i;
                // cout<<i<<endl;
                if (res > num) return false;
            }
        }
        return (res == num);
    }
};
// @lc code=end

