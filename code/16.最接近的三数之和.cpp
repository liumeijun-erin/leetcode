/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int i = 0,j = nums.size()-1;
        while(i + 1 < j && nums[i] + nums[j-1] + nums[j] < target) ++i;
        while(i + 1 < j&& nums[i] + nums[i+1] + nums[j] > target ) --j;
        if(i > 0) --i;
        if(j < nums.size()-1) ++j;
        int res = nums[i] + nums[j-1] + nums[j];
        for(int p = i;p + 1 < j;++p){
            for(int q = j;p + 1 < q;--q){
                /*for(int k = p+1;k < q;++k){
                    if(abs(nums[p] + nums[q] + nums[k] - target) < abs(res - target)){
                        res = nums[p] + nums[q] + nums[k];
                    }
                }*/
                int left = p,right = q,mid;
                int sum = nums[left] + nums[right];
                while(left + 1< right){
                    mid = (right - left)/2 + left;
                    if(nums[mid] + sum <= target) left = mid;
                    else right = mid;
                }
                if(abs(sum + nums[mid] - target) < abs(res - target)){
                    res = sum  + nums[mid];
                }
                if(mid-1 > p&&abs(sum + nums[mid-1] - target) < abs(res - target)){
                    res = sum  + nums[mid-1];
                }
            }
        }
        return res;
    }
    //[1,1,48,50,99,100,103,333,333]\n250
};
// @lc code=end

