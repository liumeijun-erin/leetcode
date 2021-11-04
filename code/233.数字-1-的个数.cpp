/*
 * @lc app=leetcode.cn id=233 lang=cpp
 *
 * [233] 数字 1 的个数
 */

// @lc code=start
class Solution {
public:
    //数学问题分情况写一些利用逻辑化简！！！
    //参考答案。策略：按位计算可能为1的个数：个位可能为1次数+十位可能为1次数...
    //参考答案集合情况具体数位分析！！！
    //按位分析的思想！分情况写一写总结规律！
    //eg：2304第二位为1有多少情况：2219-0010 ->229-000共有230种情况 所以是之前的数*10
    //eg：2314第二位为1有多少情况：2314-0010 -> 234-000共有230种情况 所以是之前的数*post位数+后面的数+1
    //eg: 2394第二位为1有多少情况：2319-0010 -> 239-000共有240种情况  之前的数+1再*post位数
    //eg: 13个位是1：11-01 ->2
    //21 21-01 19-10 10
    int countDigitOne(int n) {
        if(n == 0) return 0;
        int res = 0,post = 0;
        long long mul = 1;
        while(n){
            int pos = n%10;
            //cout<<pos<<endl;
            n /= 10;
            if(pos == 0) {
                res += n * mul;
                //cout<<n*mul<<endl;
            }
            else if(pos == 1) {
                res += (n*mul+ post + 1);
                //cout<<(n*mul+ post + 1)<<endl;
            }
            else {
                res += (n + 1)*mul;
                //cout<<(n + 1)*mul<<endl;
            }
            post += pos * mul;
            mul *= 10;
        }
        return res;
    }
};
// @lc code=end

