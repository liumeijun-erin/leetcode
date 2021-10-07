/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        int isNeg = 0;//0,1,-1:2147483648
        if(n < 0) {
            if(n == -2147483648){
                isNeg = -1;
                n = 2147483647;
            }
            else{
                isNeg = 1;
                n = -n;
            }
        }
        double tmp = myPow(x,n/2);
        double res = tmp * tmp;
        if(n%2) res *= x;
        if(isNeg == -1) res *= x;
        if(isNeg) res =  1/res;
        return res;
    }
};
// @lc code=end

