/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1,j = n - 1,k = m + n-1;
        while(j>=0){
            if(i<0||j>=0&&nums1[i] <= nums2[j]){
                nums1[k--] = nums2[j--];
            }
            else if(j<0||i>=0&&nums1[i] > nums2[j]){
                nums1[k--] = nums1[i--];
            }
        }
        //其实可以优化n<0就停下即可
    }
};
// @lc code=end

