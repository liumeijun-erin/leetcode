/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 */

// @lc code=start
class Solution {
public:
    int addDigits(int num) {
        //solution1:递归
        /*if(num<10) return num;
        int tmp = 0;
        while(num){
            tmp+=num%10;
            num/=10;
        }
        return addDigits(tmp);*/
        //solution2：参考答案，分析题目规律：！！！分析sum和各个位数和的联系：38可以看成3*(9+1)+8*1,432可以看成4*(9+1)*(9+1)+3*(9+1)+2*1,所以各个位数和可以看成sum对9取余
        //所以无论如何转换，最后各位数和<10时得到答案==一开始sum%9
        //各个位数和%9 == sum%9
        if(!num) return 0;
        if(!(num%9)) return 9;
        return num%9;
    }
};
// @lc code=end

