/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = 0, j = nums.size();
        while (i < j) {
            int mid = (j-i)/2 + i;
            if (nums[mid] == target) return mid;
            else if(nums[mid] < target) i = mid+1;
            else  j = mid;
        }
        return i;
        
        // int left = 0,right = nums.size()-1;
        // //tip1:确定区间左右含义
        // while(left <= right){
        //     //tip2:确定迭代条件，这里需要有==
        //     // cout<<left<<" "<<right<<endl;
        //     int mid = (right-left)/2+left;
        //     if(nums[mid] == target) return mid;
        //     else if(nums[mid] > target) right =mid-1;
        //     else left = mid+1;
        //     //tip3:更新方法
        // }
        // //tip4:边界条件：多思考多试
        // return left;
        //先理清定义：要返回最后一个小于的位置，然后return结果+1
        //注意如何设置才能正确返回索引：[1,3,5,6]\n2-2
        //[1,3,5,6]\n5
        //[1,3,5,6]\n6
        //[1,3,5,6]\n7-4
        //[1,3,5,6]\n1-0
    }
};
// @lc code=end

