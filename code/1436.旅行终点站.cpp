/*
 * @lc app=leetcode.cn id=1436 lang=cpp
 *
 * [1436] 旅行终点站
 */

// @lc code=start
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,int> path;//end-from
        for(const vector<string>& p:paths){
            path[p[0]] = 1;
            if(!path.count(p[1])) path[p[1]] = 0;
        }
        for(auto it = path.begin();it!=path.end();++it){
            if((*it).second == 0) return (*it).first;
        }
        return "";
    }
};
// @lc code=end

