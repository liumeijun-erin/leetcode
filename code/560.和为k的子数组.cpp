/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为K的子数组
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //参考了答案！：前缀和变形，统计各个前缀值的个数，简化O(n)
        //但是要保证顺序，不能是前面的减后面的
        //所以需要在遍历的时候判断!!!
        //考虑特殊情况[-1,1,0]等
        unordered_map<int,int> hash;
        int sum = 0;
        int res = 0;
        for(const int& num:nums){
            sum += num;
            if(sum == k) res += 1;
            if(hash.count(sum - k)) res += hash[sum - k];
            ++hash[sum];//直接这样好像就可以
            //if(hash.count(sum)) ++hash[sum];
            //else hash[sum] = 1;
        }
        return res;
    }
};
// @lc code=end

