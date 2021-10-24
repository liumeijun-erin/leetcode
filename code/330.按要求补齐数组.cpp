/*
 * @lc app=leetcode.cn id=330 lang=cpp
 *
 * [330] 按要求补齐数组
 */

// @lc code=start
class Solution {
public:
    //  本题不会。依靠答案缕清思路。
    //tip1：nums,n--按照n遍历，
    //tip2:处理nums的方法：不在tip3里单独划分，概括为+value。clever！
    //tip3:加入一个数字之后范围变化情况1-2*n-1
    //本题捋不清了，参考答案进行重构！！！！
    //已有思路大致方向对，但是有点乱.到底是遍历1-nums还是1-n
    //得到结论遍历1-n,确保1-pos都可达(而不是都在nums里)：pos若nums中没有则cnt++，此时加入pos可以确保[pos+1,2*pos-1]段可达，pos = 2*pos
    //截止条件pos == n
    //参考答案：针对！！！pos范围内有nums已经出现的数：不是求最远范围而是直接将范围内的数加和寻找！！！！！！
    int minPatches(vector<int>& nums, int n) {
        //策略：遍历1-n寻找漏洞,填充，
        //tip!!!!:对于范围中已有的nums直接加和!!!
        long long pos = 1;
        int i = 0,cnt = 0;
        while(pos <= n){
            if(i < nums.size()&&nums[i] <= pos) {
                pos += nums[i]; 
                ++i;
            }
            else{
                ++cnt;
                pos = pos * 2;
            }
        }
        return cnt;
    }
    //[1,2,31,33]\n2147483647
};
// @lc code=end

