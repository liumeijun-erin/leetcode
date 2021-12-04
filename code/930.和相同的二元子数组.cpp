/*
 * @lc app=leetcode.cn id=930 lang=cpp
 *
 * [930] 和相同的二元子数组
 */

// @lc code=start
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // map<int,vector<int> > hash;
        // vector<int> sum(nums);
        // int pre = 0;
        // for (int i = 0; i < nums.size(); ++i) {
        //     sum[i] += pre;
        //     pre += nums[i];
        //     if (hash.count(sum[i])) hash[sum[i]].emplace_back(i);
        //     else hash[sum[i]] = {i};
        // }
        // int res = 0;
        // if(hash.count(goal)) res += hash[goal].size();
        // for (int i = 0; i < sum.size(); ++i) {
        //     if (hash.count(goal + sum[i])) {
        //         for (const int& id: hash[goal+sum[i]]) {
        //             if (id > i) ++res;
        //         }
        //     }
        // }
        // return res;
        //
        //审题不是0就是1这可太简单了
        vector<int> ones;
        int pos = 0, cnt_tmp = 1, res = 0;
        while (pos < nums.size()) {
            while (pos < nums.size() && nums[pos] == 0) {
                ++cnt_tmp;
                ++pos;
            }
            if (pos < nums.size()) ones.emplace_back(cnt_tmp);
            else break;
            if (goal == 0 && cnt_tmp > 1) res += (cnt_tmp * (cnt_tmp-1))/2;
            ++pos;
            cnt_tmp = 1;
        }
        if (goal == 0 && cnt_tmp > 1) res += (cnt_tmp * (cnt_tmp-1))/2;
        if (goal == 0) return res;
        ones.emplace_back(cnt_tmp);
        // for (const int& cnt: ones) {
        //     cout<<cnt<<" ";
        // }
        // cout<<endl;
        for (int i = 0; i + goal < ones.size(); ++i) {
            res += ones[i] * ones[i + goal];
        }
        return res;
    }
};
// @lc code=end

