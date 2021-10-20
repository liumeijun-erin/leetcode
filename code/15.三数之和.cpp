/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        //参考答案：双指针!
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        int i = 0,j = nums.size()-1;
        while(i+1 < j){
            if(i > 0&&nums[i] == nums[i-1]) {
                ++i;
                continue;
            }
            if(nums[i] == 0){
                if(i + 2 < nums.size()&&nums[i+2]==0) res.emplace_back(vector<int> {0,0,0});
                break;
            }
            else if(nums[i] > 0) break;
            while(i <= j&&2*nums[i] +nums[j] > 0) --j;
            while(i <= j&&nums[i] + 2*nums[j] < 0) ++i;
            if(i > j) break;
            int k = j;
            while(i+1 < k){
                int left = i+1,right = k;
                while(left < right){
                    int mid = (right-left)/2 + left;
                    int tmp_sum = nums[mid] + nums[i] + nums[k];
                    if(tmp_sum == 0) {
                        res.emplace_back(vector<int> {nums[i],nums[mid],nums[k]});
                        break;
                    }
                    else if(tmp_sum > 0) right = mid;
                    else left = mid +1;
                }
                while(k-1 > i+1&&nums[k-1] == nums[k]) --k;
                --k; 
                if(nums[i] + 2*nums[k] < 0) break;
            }
            ++i;
        }
        return res;
    }
};
// @lc code=end

