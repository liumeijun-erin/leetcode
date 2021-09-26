/*
 * @lc app=leetcode.cn id=371 lang=cpp
 *
 * [371] 两整数之和
 */

// @lc code=start
class Solution {
public:
    int getSum(int a, int b) {
        //考虑符号相异的情况
        if(a == 0) return b;
        if(b == 0) return a;
        bool neg = false,minus = false;
        if(a<0&&b<0||a>0&&b>0){
            if(a<0) {
                a = -a;
                b = -b;
                neg = true;
            }
        }
        else {
            minus = true;
            if(a > 0){
                b = -b;
                if(a < b){
                    neg = true;
                    swap(a,b);
                }
            }
            else{
                a = -a;
                if(b > a){
                    swap(a,b);
                }
                else{
                    neg = true;
                }
               
            }
        }
        int tmp_a = a,tmp_b = b;
        while(a&&b){
            tmp_a = a^b;
            if(minus){
                tmp_b = a^b;
                tmp_b &= (~a);
            }
            else {
                tmp_b = a&b;
            }
            tmp_b <<= 1;
            b = tmp_b;
            a = tmp_a;
        }
        if(a == 0) {
            if(minus) a = -b;
            else a = b;
        }
        if(neg) a = -a;
        return a;
    }
};
// @lc code=end

