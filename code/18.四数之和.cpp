/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    // 排序+遍历ij+转化为移动二指针问题即可
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i + 3 < nums.size(); ++i) {
            if (i > 0 && nums[i-1] == nums[i] ) continue;
            if (4 * (long long)nums[i] > target) break;
            for (int j = i + 1; j + 2 < nums.size(); ++j) {
                if (nums[i] + 3 * (long long)nums[j] > target) break;
                if (j > i + 1 && nums[j-1] == nums[j]) continue;
                int p = j + 1, q = nums.size()-1;
                while (p < q) {
                    long long sum = (long long) nums[i] + nums[j] + nums[p] + nums[q];
                    if(sum == target) {
                        res.emplace_back(vector<int> {nums[i], nums[j], nums[p], nums[q]});
                        while(p+1 < q && nums[p+1] == nums[p]) ++p;
                        ++p;
                        while(p < q-1 && nums[q] == nums[q-1]) --q;
                        --q;
                    }
                    else if (sum > target) {
                        while(p < q-1 && nums[q] == nums[q-1]) --q;
                        --q;
                    }
                    else {
                        while(p+1 < q && nums[p+1] == nums[p]) ++p;
                        ++p;
                    }
                }

            }
        }
        return res;
    }
};
// @lc code=end

