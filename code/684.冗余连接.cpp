class UF{
    vector<int> id;
public:
    UF(int n):id(n){
        iota(id.begin(),id.end(),0);
    }
    int find(int p){
        while(id[p]!=p){
            p = id[p];
        }
        return p;
    }
    void connect(int p,int q){
        id[find(p)] = find(q);
    }
    bool isConnected(int p,int q){
        return find(p) == find(q);
    }
};
class Solution{
public:
    //union-find 模板
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UF uf(n+1);
        for(const vector<int>& edge:edges){
            if(uf.isConnected(edge[0],edge[1])) return edge;
            uf.connect(edge[0],edge[1]);
        }
        return vector<int>{};
    }
};