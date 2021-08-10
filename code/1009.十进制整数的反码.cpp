/*
 * @lc app=leetcode.cn id=1009 lang=cpp
 *
 * [1009] 十进制整数的反码
 */

// @lc code=start
class Solution {
public:
    int bitwiseComplement(int n) {
        //note:~是考虑前导零的取反，不能
        int cnt = 0,res = 0;
        if(!n) return 1;
        while(n){
            //cout<<(1- num&1)<<" "<<cnt<<endl;
            res = ((1- n&1) << (cnt++)) + res;
            //注意<< >>优先级特别低必须加（）
            n >>= 1;
        }
        return res;
    }
};
// @lc code=end

