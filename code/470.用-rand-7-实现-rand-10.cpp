/*
 * @lc app=leetcode.cn id=470 lang=cpp
 *
 * [470] 用 Rand7() 实现 Rand10()
 */

// @lc code=start
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        //思路：分成两个独立分数，一个rand肯定不够，那就两个
        int res7 = rand7(),res = 0;
        while(res7 == 7) res7 = rand7();
        if(res7 > 3) res = 5;
        do{
            res7 = rand7();
        }while(res7 >= 6);
        //注意两个分数应该相互独立，应该用另外一个res
        res += res7;
        return res;
        ////经过题目提示改进：从概率角度降低rand调用次数！！
        //将第一个while和第二个while区间写成一个，降低同时循环的概率
        //结果有很大提升，一下子超过99.65%
    }
};
// @lc code=end

