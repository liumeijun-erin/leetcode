/*
 * @lc app=leetcode.cn id=476 lang=cpp
 *
 * [476] 数字的补数
 */

// @lc code=start
class Solution {
public:
    int findComplement(int num) {
        //note:~是考虑前导零的取反，不能
        int cnt = 0,res = 0;
        while(num){
            //cout<<(1- num&1)<<" "<<cnt<<endl;
            res = ((1- num&1) << (cnt++)) + res;
            //注意<< >>优先级特别低必须加（）
            num >>= 1;
        }
        return res;
    }
};
// @lc code=end

