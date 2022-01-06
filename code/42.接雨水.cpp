/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        // 参考答案，三种解法都很妙
        // solution1:参考答案 策略--按段算：利用单调栈+同时计算res!!! -- O(n), O(n)
        // stack<int> s;
        // int res = 0;
        // for (int i = 0; i < height.size(); ++i) {
        //     while (!s.empty()&& height[i] > height[s.top()]) {
        //         int top = s.top();
        //         s.pop();
        //         if (s.empty()) break;
        //         int left = s.top();
        //         int cur_w = i - left - 1;
        //         int cur_h = min(height[left], height[i]) - height[top]; // 看作之前已经被height[top]填平
        //         res += cur_h * cur_w;
        //     }
        //     s.emplace(i);
        // }
        // return res;

        // solution2:参考答案-dp，策略--利用h = min(leftmax,rightmax)
        // int res = 0;
        // if (height.size() <= 2) return res;
        // vector<int> left_height(height);
        // for (int i = 1; i < height.size(); ++i) {
        //     if (left_height[i-1] > left_height[i]) left_height[i] = left_height[i-1];
        // }
        // vector<int> right_height(height);
        // for (int i = height.size()-2; i >= 0 ; --i) {
        //     if (right_height[i+1] > right_height[i]) right_height[i] = right_height[i+1];
        //     res += min(right_height[i], left_height[i]) - height[i];
        // }
        // res += min(right_height[height.size()-1], left_height[height.size()-1]) - height[height.size()-1];
        // return res;

        // solution3:参考答案-双指针!!!相当于针对solution2的空间优化 -- O(n), O(1)
        int left = 0, right = height.size()-1;
        int left_maxh = 0, right_maxh = 0;
        int res = 0;
        while (left < right) {
            left_maxh = max(left_maxh, height[left]);
            right_maxh = max(right_maxh, height[right]);
            // 对于pos == left来说，min(left_maxh,right_maxh(可能提高))
            // 所以left_maxh < right_maxh 则不会变了
            if (left_maxh < right_maxh) {
                res += left_maxh - height[left];
                ++left;
            }
            else {
                res += right_maxh - height[right];
                --right;
            }
        }
        return res;
    }
};
// @lc code=end

