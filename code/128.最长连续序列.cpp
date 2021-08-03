/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //way1：排序:+遍历O(nlogn)
        /*if(!nums.size()) return 0;
        sort(nums.begin(),nums.end());
        int pre = 0,maxn = 0,dup = 0;
        for(int i = 1;i < nums.size();++i){
            if(nums[i] == nums[i - 1]) dup++;
            else if(nums[i] != nums[i - 1] + 1) {
                maxn = max(i-pre-dup,maxn);
                pre = i;
                dup = 0;
            }
        }
        int len = nums.size() - pre-dup;
        maxn = max(len,maxn);
        return maxn;*/
        //way2：答案，依据unordered_map插入/查找/删除O(1)
        //虽然无顺序，但是相邻的还是相邻！！！O(n)
        //采用的方式是从已有的数中展开区间，利用插入/查找/删除O(1)
        //勿忘erase，否则重复查找
        //但是结果显示好像没有快太多
        unordered_set<int> hash;
        for(const int & num:nums) hash.insert(num);
        int maxn = 0;
        while(!hash.empty()){
            int cur = *(hash.begin());
            hash.erase(cur);
            int first = cur-1,last = cur + 1;
            while(hash.count(first)){
                hash.erase(first--);
            }
            while(hash.count(last)){
                hash.erase(last++);
            }
            maxn = max(maxn,last - first - 1);
        }
        return maxn;
    }
};
// @lc code=end

