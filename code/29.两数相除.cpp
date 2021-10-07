/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
class Solution {
public:
    //2147483647
    //直接做差超时
    //加速策略：由大及小
    int divide(int dividend, int divisor) {
        if(dividend == 0) return 0;
        int cnt = 0;
        bool isNeg = false;
        if(divisor == 1) return dividend;
        else if(divisor == -1){
            if(dividend == -2147483648) return 2147483647;
            else return -dividend;
        }
        else if(divisor == -2147483648){
            if(dividend == -2147483648) return 1;
            else return 0;
        }
        if(dividend < 0&&divisor < 0){
            if(dividend == -2147483648){
                dividend -= divisor;
                ++cnt;
            }
            dividend = -dividend;
            divisor = -divisor;
        }
        else if(dividend > 0&&divisor < 0){
            isNeg = true;
            divisor = -divisor;
        }
        else if(dividend<0){
            isNeg = true;
            if(dividend == -2147483648){
                dividend += divisor;
                ++cnt;
            }
            dividend = -dividend;   
        }
        int tmp = divisor;
        int tmp_cnt = 1;
        while(dividend > tmp&&tmp < 1073591824){
            tmp_cnt <<= 1 ;
            tmp <<= 1;
        }
        while(dividend >=divisor){
            while(dividend < tmp&&tmp > divisor) {
                tmp >>= 1;
                tmp_cnt >>= 1;
            }
            dividend -= tmp;
            cnt += tmp_cnt;
        }
        if(isNeg) cnt = -cnt;
        return cnt;
    }
};
// @lc code=end

