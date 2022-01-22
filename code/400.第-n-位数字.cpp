/*
 * @lc app=leetcode.cn id=400 lang=cpp
 *
 * [400] 第 N 位数字
 */

// @lc code=start
class Solution {
public:
    int findNthDigit(int n) {
        // 参考答案
        int start=1;
        long long d = 1, count=9;
        --n;
        while (n >= count){
            n -= count;
            start *= 10;
            ++d;
            count = 9 * start * d;
        }
        int num = start + n / d;
        return to_string(num)[n % d]-'0';
};
// @lc code=end

