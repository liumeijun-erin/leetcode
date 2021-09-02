/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //参考了答案：利用indegree数组！！！
        //思考极限情况：即不存在合理解的情况是怎样的--相互依赖！！
        //todo：也可以拍成dfs+visit
        vector<int> indegree(numCourses);//pre
        vector<vector<int> > next(numCourses);
        for(const vector<int>& edge:prerequisites){
            ++indegree[edge[0]];
            next[edge[1]].emplace_back(edge[0]);
        }
        vector<int> res;
        while(1){
            bool done = true;
            for(int i = 0;i < numCourses;++i){
                if(!indegree[i]){
                    done = false;
                    res.emplace_back(i);
                    indegree[i] = -1;
                    for(const int& n:next[i]){
                        --indegree[n];
                    }
                }
            }
            if(done) break;
        }
        if(res.size() != numCourses) res.clear();
        return res;
    }
};
// @lc code=end

