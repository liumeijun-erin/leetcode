/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()) return 0;
        sort(points.begin(),points.end(),[](const vector<int> & a,const vector<int> &b){return a[1]<b[1];});
        int border = points[0][1];
        int cnt = 1;
        for(int i = 1;i < points.size();++i){
            if(points[i][0] > border){
                cnt += 1;
                border = points[i][1];
            }
            
        }
        return cnt;
    }
};
// @lc code=end

