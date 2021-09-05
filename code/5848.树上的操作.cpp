/*
 * @lc app=leetcode.cn id=5848 lang=cpp
 *
 * [5848] 树上的操作
 */

// @lc code=start
class LockingTree {
    vector<int> parent;
    vector<vector<int> > children;
    vector<int> locked;
    vector<int> locked_children;
public:
    LockingTree(vector<int>& parent):parent(parent) ,locked(parent.size(),0),locked_children(parent.size(),0),children(parent.size()){
        for(int i = 1;i < parent.size();++i){
            children[parent[i]].emplace_back(i);
        }
    }
    
    bool lock(int num, int user) {
        if(locked[num] == 0){
            locked[num] = user;
            num = parent[num];
            while(num!=-1){
                ++locked_children[num];
                num = parent[num];
            }
            return true;
        }
        return false;
    }
    
    bool unlock(int num, int user) {
        if(locked[num] == user){
            locked[num] = 0;
            num = parent[num];
            while(num!=-1){
                --locked_children[num];
                num = parent[num];
            }
            return true;
        }
        return false;
    }
    
    bool upgrade(int num, int user) {
        if(locked_children[num]>0){
            int p = num;
            while(p!=-1){
                if(locked[p]) return false;
                p = parent[p];
            }
            queue<int> q;
            q.emplace(num);
            locked[num] = user;
            p = parent[num];
            while(p!=-1){
                ++locked_children[p];
                p = parent[p];
            }
            while(!q.empty()){
                int f = q.front();
                q.pop();
                if(f!=num&&locked[f]){
                    locked[f] = 0;
                    p = parent[f];
                    while(p!=-1){
                        --locked_children[p];
                        p = parent[p];
                    }
                }
                for(const int& child:children[f]){
                    q.emplace(child);
                }
            }
            return true;
        }
        return false;
    }
};



/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */
// @lc code=end

