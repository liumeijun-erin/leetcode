/*
 * @lc app=leetcode.cn id=373 lang=cpp
 *
 * [373] 查找和最小的K对数字
 */

// @lc code=start
class Solution {
public:
    // solution1-failed：暴力搜索 i, j ：[0,k) 再排序--超时：O(nlogn) n^9不行
    // solution2: 遍历一维，使用一个数组记录另一维  + priority_queue:pair<sum,id1>
    // 设计数据结构：sum-i
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int> > res;
        vector<int> id2(nums1.size(), 0);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for (int i = 0; i < nums1.size(); ++i) {
            pq.emplace(make_pair(nums1[i] + nums2[0], i));
        }
        while(k-- && !pq.empty()) {
            int id1 = pq.top().second;
            pq.pop();
            res.emplace_back(vector<int> {nums1[id1], nums2[id2[id1]]});
            ++id2[id1];
            if (id2[id1] < nums2.size())  pq.emplace(make_pair(nums1[id1] + nums2[id2[id1]], id1));
        }
        return res;
    }
};
// @lc code=end

