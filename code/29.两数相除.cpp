/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
class Solution {
public:
    // 本题不会, 参考答案
    // 策略：第一反应应该是作差->超时-->想到类二分加速，被减数由大及小
    // note1: 边界值注意超出输出INT_MAX 2147483647 
    // 策略：均负数避免溢出 + 集中考虑两者是INT_MIN / +-1的情况
    // 转化为找：z*y >= x >= z*(y+1)
    // note2：利用类二分法加速(从divisor角度位移实现，由大及小往下减+vector candidates + cnt)--从dividend角度考虑也是二分法一种
    // note3: 不能用乘法就要用 <<= 1代替 * 2-->也是选二分法的一个原因之一
    int divide(int dividend, int divisor) {
        // 处理极限值
        if (dividend == INT_MIN) {
            if (divisor == 1) return INT_MIN;
            else if(divisor == -1) return INT_MAX;
        }
        if (divisor == INT_MIN) {
            return (dividend == INT_MIN) ? 1: 0;
        }
        if (dividend == 0) return 0;
        // 采取都负策略
        bool signNeg = false;
        if (dividend > 0) {
            dividend = -dividend;
            signNeg = !signNeg;
        }
        if (divisor > 0) {
            divisor = -divisor;
            signNeg = !signNeg;
        }
        vector<int> candidates = {divisor};
        int cnt = 1;
        // 注意负数 符号取反
        // 构建二分数列
        while (candidates.back() >= dividend - candidates.back() ) {//注意溢出
            candidates.push_back(candidates.back() * 2);
            cnt <<= 1;
        }
        int res = 0;
        while (!candidates.empty()) {
            if (dividend <= candidates.back()) {
                res += cnt;
                dividend -= candidates.back();
            }
            candidates.pop_back();
            cnt >>= 1;
        }
        if (signNeg) res *= -1;
        return res;
    }
};
// @lc code=end

