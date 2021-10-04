/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 */

// @lc code=start
class Solution {
public:
    //此题不会，参考答案：桶排序！！！
    //以k为桶划分。桶内一定可以；相邻桶可能可以；相隔桶一定不可！
    //结合题目特性因此一个桶中最多只有一个元素:利用条件为返回bool值，不要过早嫌数据结构存储麻烦！
    //将按序号分段--转换坐标系--转换为数值分段，稀疏且只要保证和相邻比较即可！!!
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.empty()||!k) return false;
        long long min_num = nums[0],max_num = nums[0];
        for(const int& n:nums){
            if(n< min_num) min_num = n;
            if(n> max_num) max_num = n;
        }
        unordered_map<int, pair<long long,int> > bucket;
        for(int i = 0;i < nums.size();++i){
            long long tmp = nums[i];
            long long index = tmp -min_num;
            if(t) index /= t;//tip:注意t可能为0
            if(bucket.count(index)&&abs(bucket[index].second-i)<=k) return true;
            bucket[index] = make_pair(tmp,i);
            if(bucket.count(index-1)){
                if(abs(bucket[index-1].first-bucket[index].first)<=t&&abs(bucket[index-1].second-bucket[index].second)<=k){
                    return true;
                }
            }
            if(bucket.count(index+1)){
                if(abs(bucket[index+1].first-bucket[index].first)<=t&&abs(bucket[index+1].second-bucket[index].second)<=k){
                    return true;
                }
            }
        }
        return false;
        //[1,5,9,1,5,9]\n2\n3
        //[1,2,3,1]\n3\n0
        //[-2147483648,2147483647]\n1\n1
        //[2147483647,-1,2147483647]\n1\n2147483647
    }
};
// @lc code=end

