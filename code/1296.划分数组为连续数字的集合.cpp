/*
 * @lc app=leetcode.cn id=1296 lang=cpp
 *
 * [1296] 划分数组为连续数字的集合
 */

// @lc code=start
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() % k) return false;
        unordered_map<int,int> hash;
        sort(nums.begin(),nums.end());
        for (const int& c: nums) {
            if (hash.count(c)) ++hash[c];
            else hash[c] = 1;
        }
        int cnt = nums.size() / k;
        int pos = 0;
        for (int i = 0;i < cnt; ++i) {
            while (pos < nums.size() && hash[nums[pos]] == 0) ++pos;
            if (pos == nums.size()) return false;
            --hash[nums[pos]];
            int num = nums[pos];
            for (int j = 1; j < k; ++j) {
                ++num;
                if (!hash.count(num) || hash[num] == 0) return false;
                --hash[num];
            }
        }
        return true;
    }
};
// @lc code=end

