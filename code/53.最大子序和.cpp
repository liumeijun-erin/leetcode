/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //solution1:dp-O(n)
        //dp写的不够简洁优雅，使用min-max关系边界条件复杂
        /*if(nums.size() == 1) return nums[0];
        int minn = 0, maxn = nums[0],cur = 0,res = -10001;
        for(const int& num:nums){
            if(num == 0) res = max(0,res);
            cur += num;
            if(cur < minn){
                if(maxn != minn) res = max(res,maxn - minn);
                else res = max(res,cur-minn);
                minn = cur;
                maxn = cur;
            }
            else if(cur >= maxn){
                maxn = cur;
            }
        }
        if(maxn!=minn) res = max(res,maxn - minn);
        res = max(res,nums.back());
        return res;*/
        //solution2:dp-O(n)，更优雅写法。将数组num作为最后一位的最大和
        int res = nums[0],cur = nums[0];
        for(int i = 1;i < nums.size();++i){
            cur = max(cur,0) + nums[i];
            res = max(cur,res);
        }
        return res;
        //solution3:分治法-O(n) 线段树
    }
};
//[-2,1,-3,4,-1,2,1,-5,4]
//[5,4,-1,7,8] [5,9,8,15,23]
//[-1]
//[-2,-1]
//[-1,0,-2]
//[-2,-1,-2]
// @lc code=end

