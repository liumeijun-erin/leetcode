/*
 * @lc app=leetcode.cn id=315 lang=cpp
 *
 * [315] 计算右侧小于当前元素的个数
 */

// @lc code=start
class Solution {
public:
    //  本题过难，实在不会：离散化+桶排序
    //  attempt1:试图将后来的存成数组都sort然后二分，但是超时（因为插入的时候是O(n))
    //  attempt2:手写二叉树，但是要还要控制高度平衡以及平衡之后left怎么控制，麻烦
    //  solution:参考答案,学到新的数据结构：树状数组
    //  树状数组动态维护前缀和+使用桶(按value+cnt排列)+离散化(target_value范围太大):去重后排序
    //  tip1:整体时间复杂度高的时候不要怕多遍历两次保存中间结果，离散化+ 桶排序！！！！
    //  tip2:树状数组更新update+query+lowbit！
    int lowbit(int x){
        return x&(-x);
    }
    //注意从1开始才有作用
    void update(int i, vector<int>& C){
        while (i < C.size()) {
            ++C[i];
            i += lowbit(i);
        }
    }
    int query(int i, vector<int>&C){//注意这里的前缀和包括i
        int sum = 0;
        while (i >= 1) {
            sum += C[i];
            i -= lowbit(i);
        }
        return sum;
    }
    vector<int> countSmaller(vector<int>& nums) {
        map<int,int> hash;
        for(const int& n:nums){
            hash[n] = 0;
        }
        int cnt = 1;
        for(auto it = hash.begin();it != hash.end();++it){
            it->second = cnt++;
        }
        vector<int> bucket(cnt,0);
        vector<int> res(nums.size(),0);
        //存中间结果
        for(int i = nums.size()-1;i >= 0;--i){
            int index = hash[nums[i]];// bucket
            update(index,bucket);
            res[i] = query(index-1,bucket);
        }
        return res;
    }
};
// @lc code=end

