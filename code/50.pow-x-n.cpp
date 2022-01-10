/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    // double myPow(double x, int n) {
    //     if(n == 0) return 1;
    //     int isNeg = 0;//0,1,-1:2147483648
    //     if(n < 0) {
    //         if(n == -2147483648){
    //             isNeg = -1;
    //             n = 2147483647;
    //         }
    //         else{
    //             isNeg = 1;
    //             n = -n;
    //         }
    //     }
    //     double tmp = myPow(x,n/2);
    //     double res = tmp * tmp;
    //     if(n%2) res *= x;
    //     if(isNeg == -1) res *= x;
    //     if(isNeg) res =  1/res;
    //     return res;
    // }
    // 注意负数 偶数次幂为+
    double help(double& x, long long n) {
        if (n == 0||x == 1) return 1;
        if (n == 1) return x;
        double res = help(x, n/2);
        res *= res;
        if (n%2) res*= x;
        return res;
    }
    double myPow(double x, int n) {
        bool neg1 = false, neg2 = false;
        long long nn = n;
        if (nn < 0) {
            neg2 = true;
            nn = -nn;
        }
        if (x < 0) {
            if(n%2) neg1 = true;
            x = -x;
        }  
        double res = help(x, nn);
        if (neg2) res = 1.0/res;
        if (neg1) res = -res;
        return res;
    }
};
// @lc code=end

