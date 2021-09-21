/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H 指数
 */

// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        if(citations[citations.size()-1]<=0) return 0;
        for(int i = citations.size()-1;i>=1;--i){
            if(citations[i-1]<=citations.size()-i) return citations.size()-i;
        }
        return citations.size();
    }
};
// @lc code=end

