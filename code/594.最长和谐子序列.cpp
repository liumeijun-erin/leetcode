/*
 * @lc app=leetcode.cn id=594 lang=cpp
 *
 * [594] 最长和谐子序列
 */

// @lc code=start
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> m;
        int maxn = 0;
        for(const int& num:nums){
            ++m[num];
            if(m.count(num-1)) maxn = max(maxn,m[num] + m[num-1]);
            if(m.count(num+1)) maxn = max(maxn,m[num] + m[num+1]);
        }
        return maxn;
    }
};
// @lc code=end

