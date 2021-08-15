/*
 * @lc app=leetcode.cn id=310 lang=cpp
 *
 * [310] 最小高度树
 */

// @lc code=start
class Solution {
public:
    int bfs(int node,vector<vector<int> > new_edges,int & leaf,vector<int>& parent) {
        queue<int> q;
        q.emplace(node);
        int cnt  = 1,front;
        while(!q.empty()){
            int len = q.size();
            while(len--){
                front = q.front();
                q.pop();
                for(const int& child:new_edges[front]){
                    if(parent[child] == -1) {
                        parent[child] = front;
                        q.emplace(child);
                    }
                }
            }
            ++cnt;
        }
        leaf = front;
        return cnt;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        //想清楚再写，不能瞎写一气
        if(n == 1) return vector<int> {0};
        if(n == 2) return vector<int> {0,1};
        vector<int> parent(n,-1);
        vector<vector<int> > new_edges(n);
        for(const auto& edge:edges){
            new_edges[edge[0]].emplace_back(edge[1]);
            new_edges[edge[1]].emplace_back(edge[0]);
        }
        int root = 0,leaf;
        while(new_edges[root].size() == 1) ++root;
        cout<<root<<endl;
        //问题在于如何找到经过中间点两叉最大值
        //这里使用多个层次遍历，取前两位
        int a = -1,b = -1;
        int a_node = root,b_node = root;
        for(const int& node:new_edges[root]){
            parent[node] = root;
            int height = bfs(node,new_edges,leaf,parent);
            if(height > b) {
                b = height;
                b_node = leaf;
                if(a < b) {
                    swap(a,b);
                    swap(a_node,b_node);
                }
                cout<<a<<" "<<b<<endl;
                cout<<a_node<<" "<<b_node<<endl;
            }
        }
        while(a_node!= root&&b_node!=root){
            a_node = parent[a_node];
            b_node = parent[b_node];
        }
        vector<int> res;
        if(a_node == b_node) res.emplace_back(root);
        else {
            int bottom,len = 0,cur;
            if(a_node == root) bottom = b_node;
            else if(b_node == root) bottom = a_node;
            cur = bottom;
            while(cur != root){
                cur = parent[cur];
                ++len;
            }
            if(len&1){
                len /=2;
                while(len--){
                    bottom = parent[bottom];
                }
                res.emplace_back(bottom);
                res.emplace_back(parent[bottom]);
            }
            else{
                len /= 2;
                while(len--){
                    bottom = parent[bottom];
                }
                res.emplace_back(bottom);
            }
        }
        return res;
    }
};
//10\n[[0,3],[1,3],[2,3],[4,3],[5,3],[4,6],[4,7],[5,8],[5,9]]
// @lc code=end

