/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    //   利用有序+查找 所以可以用二分
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return vector<int> {-1,-1};
        int cnt = 0;
        int l = 0, r = nums.size(), m;
        while (l < r) {
            m = (r - l)/2 + l;
            if (nums[m] > target) r = m;
            else l = m + 1;
        }
        --r;
        int right = r;
        // cout<<right<<endl;
        if (right <0 ||nums[right] != target)  return vector<int> {-1,-1};
        l = 0;
        while (l < r) {
            m = (r - l)/2 + l;
            if (target <= nums[m]) r = m;
            else l = m + 1 ;
        }
        // cout<<l<<endl;
        if (l <= right) return vector<int> {l,right};
        return vector<int> {-1,-1};
        // [5,7,7,8,8,10]\n6
        // []\n0
        // [1]\n1
        // [1]\n0
        // [1]\n2
    }
};
// @lc code=end

