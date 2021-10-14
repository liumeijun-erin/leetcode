/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> hash;
        for(const int& num:nums1){
            if(hash.count(num)) ++hash[num];
            else hash[num] = 1;
        }
        vector<int> res;
        for(const int& num:nums2){
            if(hash.count(num)&&hash[num]) {
                --hash[num];
                res.emplace_back(num);
            }
        }
        return res;
    }
};
// @lc code=end

