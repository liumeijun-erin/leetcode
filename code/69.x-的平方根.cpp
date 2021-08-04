/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        if(x == 1||x == 0) return x;
        int left =  1,right = x;
        //左闭右开区间
        while(left < right -1 ){
            //然后考虑只有2/1/没有元素的时候
            //思路2：答案判断mid 是否== x/mid，这样不用考虑超界限
            double mid = left +(right - left)/2;
            //tip：乘积考虑中介
            if((mid + 1)*(mid +1) <= x) left = mid + 1;
            else if(mid * mid <= x&&(mid + 1)*(mid +1) > x) return mid;
            else if(mid * mid > x) right= mid;
        }
        return left;
        //way3:求解数学方程，可用牛顿迭代
        /*
        int mySqrt(int a) {
            long x = a;
            while (x * x > a) {
                x = (x + a / x) / 2;
            }   
            return x;
        }
        */
    }
};
// @lc code=end

