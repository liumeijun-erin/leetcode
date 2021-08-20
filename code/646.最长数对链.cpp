/*
 * @lc app=leetcode.cn id=646 lang=cpp
 *
 * [646] 最长数对链
 */

// @lc code=start
class Solution {
public:
    static bool cmp(vector<int> &pair1,vector<int>& pair2){
        if(pair1[1] == pair2[1]) return pair1[0] < pair2[0];
        else return pair1[1] < pair2[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),cmp);
        int cnt = 0,pre = pairs[0][0]-1;
        for(const auto& p:pairs){
            if(p[0] > pre){
                ++cnt;
                pre = p[1];
            }
        }
        return cnt;
        //todo：使用线段树
    }
};
// @lc code=end

