/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
class Solution {
public:
    int integerBreak(int n) {
        if(n == 2) return 1;
        if(n == 3) return 2;
        if(n == 4) return 4;
        int cur = 4;
        for(int i = 5;i <= n;++i){
            if((i-5)%3 < 2) cur = cur*3/2;
            else cur = cur*4/3;
            //cout<<cur<<endl;
        }
        return cur;
    }
};
//1*1-1
//1*2-1
//2*2-2
//2*3-2
//3*3-3
//3*2*2-2
//3*3*2-2
//3*3*3-3
//3*3*2*2-2
//3*3*3*2-2
// @lc code=end

