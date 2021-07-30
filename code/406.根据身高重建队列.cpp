/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
class Solution {
public:
    static bool cmp(const vector<int>& a,const vector<int> &b){
        if(a[0] != b[0]) return a[0] > b[0];
        else return a[1] < b[1];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),cmp);
        vector<vector<int> > res;
        for(const auto& person:people){
            res.insert(res.begin() + person[1],person);
        }
        return res;
    }
};
// @lc code=end

