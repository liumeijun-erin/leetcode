/*
 * @lc app=leetcode.cn id=400 lang=cpp
 *
 * [400] 第 N 位数字
 */

// @lc code=start
class Solution {
public:
    int findNthDigit(int n) {
        if(n < 10) return n;
        n -= 10;
        int cnt = 2;
        int tmp = 90;
        while(n > (long long)tmp * cnt){
            n -= cnt * tmp;
            tmp *= 10;
            ++cnt;
        }
        int digit = cnt - n % cnt - 1 ;
        //cout<<digit<<" ";
        n = n / cnt + tmp / 9 ;
        //cout<<n<<endl;
        while(digit--){
            n /= 10;
        }
        return n%10;
    }
};
// @lc code=end

