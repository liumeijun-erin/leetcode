/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(),-1);
        stack<int> s;
        int n = nums.size();
        for(int i = 0;i < 2 * n;++i){
            while(!s.empty()&&nums[i%n] > nums[s.top()]) {
                res[s.top()] = nums[i%n];
                s.pop();
            }
            s.push(i%n);    
        }
        return res;
    }
};
// @lc code=end

