/*
 * @lc app=leetcode.cn id=882 lang=cpp
 *
 * [882] 细分图中的可到达结点
 */

// @lc code=start
class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        //note1:!!!!priority_queue默认降序！！！！！！！！写了一天太蠢了！！！
        //tip1:参考答案使用used记录覆盖区域即可，不用每次纠结于具体值。这样可以简便一些
        //但是每次直接加硬写也可以
        //a bit tricky:
        //要事先设计好数据结构，不能到时候临时改！
        //要考虑极限即与0不联通的情况！
        //而且要注意不是最小生成树，每次不挑最短边而是挑最短路径，同时还要记录路径上的边
        //res加的有点混乱
        priority_queue<pair<int,int >,vector<pair<int,int > >,greater<pair<int,int >>> p;//到源点的距离，节点号
        vector<int> visited(n,maxMoves+1);//记录已确定的最小距离
        vector<vector<vector<int> > > graph(n);//没有用到快速查找且map删除操作较麻烦
        unordered_map<int,int> used;//这里借鉴了答案,记录边的使用情况
        for(const vector<int>& edge:edges){
            graph[edge[0]].emplace_back(vector<int> {edge[1],edge[2]});
            graph[edge[1]].emplace_back(vector<int> {edge[0],edge[2]});
        }
        p.emplace(make_pair(0,0));
        int res = 0;
        while(!p.empty()){
            int value = p.top().first;
            int to = p.top().second;
            p.pop();
            if(visited[to]<=value) continue;
            ++res;     
            visited[to] = value;
            //参考答案使用used记录覆盖区域最后再一起加即可！！！！
            for(vector<int> edge:graph[to]){
                used[3000*to+edge[0]] = min(maxMoves-value,edge[1]);//参考答案这里记录覆盖区域！！！！
                int d = edge[1]+visited[to]+1;
                if(d <visited[edge[0]]){
                    p.emplace(make_pair(d,edge[0]));
                }
            }
        }
        for(const vector<int> edge:edges){
            //勿忘利用edges
            int u= edge[0],v = edge[1],w = edge[2];
            res += min(used[3000*u+v]+used[3000*v+u],w);
        }
        return res;

    }
    //[[1,3,9],[1,5,24],[2,5,4],[3,6,7],[1,2,12],[3,7,23],[2,8,24],[0,1,0],[6,8,16],[5,6,6],[2,6,17],[0,7,19],[3,4,23],[1,7,17],[4,7,22],[7,9,20],[8,9,4],[0,6,1],[5,7,19],[4,5,13],[3,5,25],[2,4,4],[1,9,10],[3,9,7],[5,8,22]]\n23\n10
    //[[1,3,23],[3,5,19],[3,6,17],[1,5,14],[6,7,20],[1,4,10],[1,6,0],[3,4,20],[1,7,4],[0,4,10],[0,7,9],[2,3,3],[3,7,9],[5,7,4],[4,5,16],[0,1,16],[2,6,0],[4,7,11],[2,5,14],[5,6,22],[4,6,12],[0,6,2],[0,2,1],[2,4,22],[2,7,20]]\n19\n8
    //[[1,2,4],[1,4,5],[1,3,1],[2,3,4],[3,4,5]]\n17\n5
    //[[2,4,2],[3,4,5],[2,3,1],[0,2,1],[0,3,5]]\n14\n5
};

// @lc code=end

