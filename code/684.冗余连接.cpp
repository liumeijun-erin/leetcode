class UF{
    vector<int> id,size;
public:
    UF(int n):id(n),size(n,1){
        iota(id.begin(),id.end(),0);
    }
    int find(int p){
        while(id[p]!=p){
            id[p] = id[id[p]];
            p = id[p];
        }
        return p;
    }
    void connect(int p,int q){
        int i = find(p),j = find(q);
        if(i!=j){
            if(size[i] < size[j]){
                id[i] = j;
                size[j] += size[i];
            }
            else{
                id[j] = i;
                size[i] += size[j];
            }
        }
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