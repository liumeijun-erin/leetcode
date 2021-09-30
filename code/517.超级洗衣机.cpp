/*
 * @lc app=leetcode.cn id=517 lang=cpp
 *
 * [517] 超级洗衣机
 */

// @lc code=start
class Solution {
public:
    //思路：取某个堆左右向向外发射的max,然后取各堆max；即左右的max
    //这里漏掉了不是左右max，左右应该加和！！！
    //参考了答案，简洁优雅！！！！分类+两种情况确定具体值！！
    int findMinMoves(vector<int>& machines) {
        int n = machines.size();
        int sum = accumulate(machines.begin(),machines.end(),0);
        if(sum%n) return -1;
        int avg = sum/n;
        int res = 0;
        sum = 0;
        //注意这里machine到底是累计还是没有要注意
        //next = (n-i-1)*svg-(sum - pre - machines[i])
        //next = -(i+1)*svg+pre+machines[i]
        //整体思路对了，但是具体写法参考了答案
        //参考答案！
        ///!!!即两种移动方式，一个值特大往两侧走，且走值之和固定；否则就是一个方向且为定值！
        for(int&num:machines){
            num -= avg;//参考答案通过这种情况即可处理两侧出值的情况！！因为最后是avg
            sum += num;//左右组间流通值用一个即可表示
            res = max(res,max(abs(sum),num));//注意左右进值不加和！
        }
        return res;
        //[0,0,4,0,5,0,5,0,4] -4
        //[0,0,11,5] -8
        //[1,0,5] -3
        //[0,3,0] -1
        //[4,0,0,4] -2
    }
};
// @lc code=end

