/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */

// @lc code=start
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int cnt = 0;
        string tmp = "";
        for(int i = 0;i < nums.size();++i){
            if(i == 0){
                tmp = to_string(nums[i]);
                cnt = 1;
            }
            else if(nums[i] != nums[i-1] + 1){
                if(cnt > 1) tmp += ("->" + to_string(nums[i-1]));
                res.emplace_back(tmp);
                tmp = to_string(nums[i]);
                cnt = 1;
            }
            else ++cnt;
        }
        if(cnt > 1) tmp += ("->" + to_string(nums[nums.size()-1]));
        if(tmp.size()) res.emplace_back(tmp);
        return res;
    }
};
// @lc code=end

