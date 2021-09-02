/*
 * @lc app=leetcode.cn id=785 lang=cpp
 *
 * [785] 判断二分图
 */

// @lc code=start
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int num = graph.size();
        if(!num) return false;
        vector<int> visit(num);
        for(int i = 0;i < num;++i){
            if(graph[i].empty()) continue;
            if(visit[i] == 0){
                //先滤清关系，不连通图需要从各个节点开始bfs遍历一下；然后已经有遍历记录的跳过
                visit[i] = 1;
                queue<int> q;
                q.emplace(i);
                while(!q.empty()){
                    int f = q.front();
                    q.pop();
                    for(const int& j:graph[f]){
                        if(visit[j] == visit[f]) return false;
                        else if(!visit[j]){
                            visit[j] = -visit[f];
                            q.emplace(j);
                        }
                    }
                }
            }
        }
        return true;
    }
};
// @lc code=end

