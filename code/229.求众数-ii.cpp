/*
 * @lc app=leetcode.cn id=229 lang=cpp
 *
 * [229] 求众数 II
 */

// @lc code=start
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //solution1:hash
        /*unordered_map<int,int> hash;
        vector<int> res;
        for(const int& num:nums){
            if(hash.count(num)) ++hash[num];
            else hash[num] = 1;
        }
        for(auto it = hash.begin();it!= hash.end();++it){
            if(it->second > nums.size()/3) res.emplace_back(it->first);
        }
        return res;*/
        //solution2：参考摩尔投票法思想1vs2,leetcode169
        //思路对但是写的太混乱，重新整理：核心思想--每次消掉三个不一样的数字，同时保留cur1/2和cnt1/2而不用多次遍历
        //而且本题没有说确保有解，所以需要判断：能确保符合要求的都留下来，但是留下来的不一定符合要求
        //note:也加深了对摩尔投票的理解：每次消掉两个/三个不一样的数字！！
        //而不用两次一消二
        if(nums.size()==1) return nums;
        if(nums[0]==nums[1]&&nums.size()==2) return vector<int>{nums[0]};
        int i = 1;
        int cur1 = nums[0],cnt1 = 1;
        while(i<nums.size()&&nums[i] == cur1){
            ++cnt1;
            ++i;
        }
        if(i == nums.size()) return vector<int> {cur1};
        int cur2 = nums[i],cnt2 = 1;
        for(i = i+1;i < nums.size();++i){
            if(cnt1&&nums[i]==cur1) ++cnt1;
            else if(cnt2&&nums[i]==cur2) ++cnt2;
            else if(cnt1&&cnt2){
                --cnt1;
                --cnt2;
            }
            else if(!cnt1){
                cnt1 = 1;
                cur1 = nums[i];
            }
            else if(!cnt2){
                cnt2 = 1;
                cur2 = nums[i];
            }
        }
        cnt1 = 0;
        cnt2 = 0;
        for(const int& num:nums){
            if(num == cur1) ++cnt1;
            else if(num == cur2) ++cnt2;
        }
        vector<int> res;
        if(cnt1 > nums.size()/3) res.emplace_back(cur1);
        if(cur1!=cur2&&cnt2 > nums.size()/3) res.emplace_back(cur2);
        //[2,1,1,3,1,4,5,6]
        return res;
    }
};
// @lc code=end

