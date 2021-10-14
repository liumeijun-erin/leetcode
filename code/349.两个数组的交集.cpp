/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //set_intersection用法!第五个参数为insert_iterator!
        set<int> s1,s2;
        for(const int& n:nums1){
            s1.insert(n);
        }
        for(const int& n:nums2){
            s2.insert(n);
        }
        vector<int> res;
        set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),insert_iterator<vector<int>>(res,res.begin()));
        return res;
    }
};
// @lc code=end

