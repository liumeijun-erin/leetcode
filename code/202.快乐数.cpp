/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        while(n>10&&n%10 == 0) n /= 10;
        if(n == 1) return true;
        if(n<=3) return false;
        else{
            int res = 0;
            while(n) {
                int num = n%10;
                res += num * num;
                n = n/10;
            }
            //cout<<res<<endl;
            return isHappy(res);
        } 
    }
};
// @lc code=end

