/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;
        for(int i = 0;i < nums.size();i++){
            q.push(nums[i]);
        }
        for(int i = 1;i < k;i++){
            q.pop();
        }
        return q.top();
    }
};
// @lc code=end

