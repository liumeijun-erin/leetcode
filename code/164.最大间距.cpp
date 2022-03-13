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
        if (nums.size() <= 1) return 0;

        int min_num = INT_MAX, max_num = -1;
        for (const int& num: nums) {
            min_num = min(min_num, num);
            max_num = max(max_num, num);
        }
        if (max_num == min_num) return 0;

        int bucket_len = (max_num - min_num) / (nums.size()-1);
        bucket_len = max(1, bucket_len);
        int cnt = (max_num - min_num)/ bucket_len + 1;
        vector<pair<int,int> > bucket(cnt, make_pair(INT_MAX, -1));
        for (const int& num : nums) {
            int bucket_id = (num - min_num) / bucket_len;
            bucket[bucket_id].first = min(bucket[bucket_id].first, num);
            bucket[bucket_id].second = max(bucket[bucket_id].second, num);
        }
        int res = bucket_len;
        int pre = -1;
        for (pair<int,int>& p: bucket) {
            if (p.first == INT_MAX) continue;
            if (pre != -1) {
                res = max(res, p.first - pre);
            }
            pre = p.second;
        }
        return res;
    }
};
// @lc code=end

