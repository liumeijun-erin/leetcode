/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int> > pre(numCourses);
        vector<int> pre_cnt(numCourses);
        for(const vector<int>& pair:prerequisites){
            pre[pair[1]].emplace_back(pair[0]);
            ++pre_cnt[pair[0]];
        }
        int cnt = 0;
        while(cnt < numCourses){
            bool isStuck = true;
            for(int i = 0;i < numCourses;++i){
                if(pre_cnt[i]==0){
                    for(const int& next:pre[i]){
                        --pre_cnt[next];
                    }
                    pre_cnt[i]=-1;
                    ++cnt;
                    isStuck = false;
                }
            }
            if(isStuck) break;
        }
        if(cnt == numCourses) return true;
        return false;
    }
};
// @lc code=end

