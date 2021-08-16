/*
 * @lc app=leetcode.cn id=310 lang=cpp
 *
 * [310] 最小高度树
 */

// @lc code=start
class Solution {
public:
    //solution1：使用深搜了，勉勉强强凑上了算是
    /*int dfs(int root,int& a,int& b,vector<vector<int> >& new_edges,vector<int>&parent,int& max_len,int&left,int&right,int&pnt){
        int len_a=0,len_b=0,cur_a = root,cur_b = root;
        for(const int& node:new_edges[root]){
            if(parent[node]!=-1) continue;
            parent[node] = root;
            int len = dfs(node,a,b,new_edges,parent,max_len,left,right,pnt);
            if(len > len_b){
                len_b = len;
                cur_b = a;
                if(len_b > len_a){
                    swap(len_a,len_b);
                    swap(cur_a,cur_b);
                }
            }
        }
        a = cur_a;
        b = cur_b;
        if(len_a + len_b > max_len){
            max_len = len_a + len_b;
            left = a;
            right = b;
            pnt = root;
        } 
        cout<<pnt<<" "<<left<<" "<<right<<endl;
        return len_a + 1;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        //想清楚再写，不能瞎写一气!!!
        if(n == 1) return vector<int> {0};
        //if(n == 2) return vector<int> {0,1};
        vector<int> parent(n,-1);
        vector<vector<int> > new_edges(n);
        for(const auto& edge:edges){
            new_edges[edge[0]].emplace_back(edge[1]);
            new_edges[edge[1]].emplace_back(edge[0]);
        }
        int root = 0,a = 0,b = 0,max_len = 0;
        parent[root] = root;
        int left = 0,right = 0,pnt = 0;
        dfs(root,a,b,new_edges,parent,max_len,left,right,pnt); 
        while(left!=pnt&&right!=pnt){
            left = parent[left];
            right = parent[right];
        }
        if(left == right) return {left};
        else if(parent[left] == right||parent[right] == left) return{left,right}; 
        //注意这里有问题，parent[root] == root
        else{
            int d = 0,bottom,cur;
            if(left == pnt) bottom = right;
            else bottom = left;
            cur= bottom;
            while(bottom!=pnt){
                bottom = parent[bottom];
                ++d;
            }
            cout<<d<<endl;
            if(d&1){
                d/=2;
                while(d--) cur = parent[cur];
                return vector<int> {parent[cur],cur};
            }
            else{
                d /=2;
                while(d--) cur = parent[cur];
                return vector<int> {cur};
            }
            
        }
    }*/
    //solution2:之前也有的思路，从叶节点出发bfs，但是边界没有控制好:
    //结合答案!!:每次都从只有一个节点的地方入手即可queuesize == 2即可
    //结合答案改进：不用修改边组erase等操作可以免，直接记录+修改indegree即可！！！！
    //省去大量复杂操作也可以用简单数据结构
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return vector<int> {0};
        if(n == 2) return vector<int> {0,1};
        vector<vector<int> > new_edges(n);
        vector<int> count(n,0);
        for(const auto& edge:edges){
            new_edges[edge[0]].emplace_back(edge[1]);
            new_edges[edge[1]].emplace_back(edge[0]);
            ++count[edge[0]];
            ++count[edge[1]];
        }
        queue<int> q;
        for(int i = 0;i < n;++i){
            if(count[i] == 1){
                q.emplace(i);
            }
        }
        vector<int> res;
        int cnt = 0,front;
        while(!q.empty()){
            int len = q.size();
            while(len--){
                front = q.front();
                q.pop();
                ++cnt;
                for(const int& i:new_edges[front]){
                    --count[front];
                    if(--count[i] == 1) q.emplace(i);
                }
            }
            if(cnt >= n-2) break;
        }
        while(!q.empty()) {
            res.emplace_back(q.front());
            q.pop();
        }
        return res;
    }
};
//6\n[[0,1],[0,2],[0,3],[3,4],[4,5]]
//6\n[[3,0],[3,1],[3,2],[3,4],[5,4]]
//14\n[[0,1],[1,2],[1,3],[2,4],[0,5],[1,6],[2,7],[6,8],[3,9],[3,10],[8,11],[2,12],[10,13]]
//10\n[[0,3],[1,3],[2,3],[4,3],[5,3],[4,6],[4,7],[5,8],[5,9]]
// @lc code=end

