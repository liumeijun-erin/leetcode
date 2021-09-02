/*
 * @lc app=leetcode.cn id=882 lang=cpp
 *
 * [882] 细分图中的可到达结点
 */

// @lc code=start
class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        //a bit tricky
        //要事先设计好数据结构，不能到时候临时改！
        //要考虑极限即与0不联通的情况！
        //而且要注意不是最小生成树，每次不挑最短边而是挑最短路径，同时还要记录路径上的边
        //res加的有点混乱
        priority_queue<pair<int,pair<int,int> > > p;
        int res = 1;
        vector<int> visited(n,-1);
        visited[0] = 0;
        vector<unordered_map<int,int> > graph(n);
        for(const vector<int>& edge:edges){
            graph[edge[0]][edge[1]] = edge[2];
            graph[edge[1]][edge[0]] = edge[2];
        }
        for(auto& v:graph[0]){
            if(v.second <= maxMoves){
                res += v.second;
                graph[v.first].erase(0);
                if(v.second < maxMoves) p.emplace(make_pair(v.second+1,make_pair(v.first,0)));
                graph[v.first].erase(0);
                graph[0][v.first] = -1;
            }
        }
        while(!p.empty()){
            int value = p.top().first;
            int to = p.top().second.first;
            int from = p.top().second.second;
            p.pop();
            if(visited[to]!=-1) continue;
            visited[to] = value;
            ++res;     
            for(auto& v:graph[to]){
                if(v.second+visited[to]<=maxMoves){
                    res += v.second;
                    graph[v.first].erase(to);
                    if(visited[v.first]==-1&&v.second+visited[to]<maxMoves) p.emplace(make_pair(v.second+visited[to]+1,make_pair(v.first,to)));
                    graph[to][v.first] = -1;
                }
            }
        }
        cout<<res<<endl;
        cout<<visited[0]<<" "<<visited[1]<<" "<<visited[2]<<endl;
        for(int i = 0;i < n;++i){
            for(auto&v : graph[i]){
                if(v.first>i) continue;
                if(v.second == -1) continue;
                if(visited[i]!=-1&&visited[v.first]!=-1){
                    res += min(2*maxMoves - visited[v.first] - visited[i],v.second);
                    cout<<i<<" 1 "<<v.first<<" "<<res<<endl;
                }
                else if(visited[i]!=-1) {
                    res += min(maxMoves- visited[i],v.second);
                    cout<<i<<" 2 "<<v.first<<" "<<res<<endl;
                }
                else if(visited[v.first]!=-1) {
                    res += min(maxMoves - visited[v.first],v.second);
                    cout<<i<<" 3 "<<v.first<<" "<<res<<endl;
                }
            }
        }
        cout<<res<<endl;
        return res;
    }
    //[[1,3,9],[1,5,24],[2,5,4],[3,6,7],[1,2,12],[3,7,23],[2,8,24],[0,1,0],[6,8,16],[5,6,6],[2,6,17],[0,7,19],[3,4,23],[1,7,17],[4,7,22],[7,9,20],[8,9,4],[0,6,1],[5,7,19],[4,5,13],[3,5,25],[2,4,4],[1,9,10],[3,9,7],[5,8,22]]\n23\n10
    //[[1,3,23],[3,5,19],[3,6,17],[1,5,14],[6,7,20],[1,4,10],[1,6,0],[3,4,20],[1,7,4],[0,4,10],[0,7,9],[2,3,3],[3,7,9],[5,7,4],[4,5,16],[0,1,16],[2,6,0],[4,7,11],[2,5,14],[5,6,22],[4,6,12],[0,6,2],[0,2,1],[2,4,22],[2,7,20]]\n19\n8
    //[[1,2,4],[1,4,5],[1,3,1],[2,3,4],[3,4,5]]\n17\n5
};
// @lc code=end

