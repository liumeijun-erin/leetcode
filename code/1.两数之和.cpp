/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*
        //runtime beats 10.04 %,memory usage beats 5.02 %
        map<int,vector<int> > m;
        for(int i = 0;i < nums.size();i++){
            if(m.find(nums[i])!= m.end()) m[nums[i]].push_back(i);
            else m[nums[i]] = vector<int> {i};
        }
        map<int,vector<int> >::iterator it1 = m.begin();
        map<int,vector<int> >::reverse_iterator it2 = m.rbegin();
        vector<int> res;
        while(1){
            if(it1->second.size()>1 && it1->first * 2 == target){
                res.push_back(it1->second[0]);
                res.push_back(it1->second[1]);
                break;
            }
            else if(it1->first + it2->first == target){
                res.push_back(it1->second[0]);
                res.push_back(it2->second[0]);
                break;
            }
            else if(it1->first + it2->first > target){
                if(it1->second.size()>1 && it1->first * 2 == target){
                    res.push_back(it1->second[0]);
                    res.push_back(it1->second[1]);
                    break;
                }
                else{
                    it2++;
                }
            }
            else{
                it1++;
            }
        }
        return res;*/
        //{} auto =>vector,much faster!
        unordered_map<int,int> m;
        for(int i = 0;i < nums.size();i++){
            if(m.find(nums[i]) != m.end()) {
                return {m[nums[i]], i};
            }
            else m[target-nums[i]] = i;
        }
       return {};
    }
};
// @lc code=end

