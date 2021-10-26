/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
class Solution {
public:
    //think first！nums2当前递增直接有解，当前递减保持
    //单调栈!!保持递减状态
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> hash;
        for(const int&n:nums1) hash[n] = -1;
        stack<int> s;
        for(int i = 0;i < nums2.size();++i){
            while(!s.empty()&&nums2[i] > nums2[s.top()]){
                if(hash.count(nums2[s.top()])) hash[nums2[s.top()]] = nums2[i];
                s.pop();
            }
            s.emplace(i);
        }
        vector<int> res;
        for(const int&n:nums1) res.emplace_back(hash[n]);
        return res;
    }
};
// @lc code=end

