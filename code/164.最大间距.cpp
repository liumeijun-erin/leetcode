/*
 * @lc app=leetcode.cn id=164 lang=cpp
 *
 * [164] 最大间距
 */

// @lc code=start
class Solution {
public:
    //本题不会
    //参考答案，桶排序--桶划分思路见下
    //思路：控制已知--(max-min)/(nums.size()-1)最大的差值一定大于等于这个值，因此小于等于这些的都不管，放到桶里黑盒+桶内显示最大最小值！
    //因此可以左闭右开分桶，桶内维护最大最小值，然后遍历桶边界即可
    //根本策略：！！！在O(n)时间复杂度下保留想要信息完成排序
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        int max_n = nums[0],min_n = nums[0];
        for(const int&num:nums){
            max_n = max(max_n,num);
            min_n = min(min_n,num);
        }
        int d = (max_n - min_n)/(nums.size()-1);
        d = max(1,d);
        //note:考虑d为0情况：
        int cnt = (max_n - min_n)/d + 1;
        vector<pair<int,int> > bucket(cnt,make_pair(-1,-1));
        for(const int&num:nums){
            int tmp = (num-min_n)/d;
            if(bucket[tmp].first == -1) {
                bucket[tmp].first = num;
                bucket[tmp].second = num;
            }
            else if(bucket[tmp].first > num) bucket[tmp].first = num;
            else if(bucket[tmp].second < num) bucket[tmp].second = num;
        }
        int pre = 0,res = 0;
        while(pre < cnt && bucket[pre].first == -1) ++pre;
        for(int i = pre + 1;i < cnt;++i){
            if(bucket[i].first == -1) continue;
            if(bucket[i].first - bucket[pre].second > res) res = bucket[i].first - bucket[pre].second;
            pre = i;
        }
        return res;
    }
};
// @lc code=end

