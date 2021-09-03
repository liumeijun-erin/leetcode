/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 */

// @lc code=start
class LRUCache {
    /*solution1:qpop的位置上可能最坏可能会O(n)
    int cap;
    unordered_map<int,pair<int,int> > cache;
    queue<pair<int,int> > q;
    int time;
public:
    LRUCache(int capacity){
        cap = capacity;
        time = 0;
    }
    int get(int key) {
        ++time;
        if(cache.count(key)) {
            cache[key].second = time;
            q.emplace(make_pair(key,time));
            return cache[key].first;
        }
        return -1;
    }
    
    void put(int key, int value) {
        ++time;
        if(!cache.count(key)&&cache.size()==cap) {
            int fk,ft;
            while(!q.empty()){
                fk = q.front().first;
                ft = q.front().second;
                q.pop();
                if(!cache.count(fk)) continue;
                if(cache[fk].second != ft) continue;
                break;
            }
            cache.erase(fk);
        }
        cache[key].first = value;
        cache[key].second = time;
        q.emplace(make_pair(key,time));
    }*/
    //solution2：参考答案使用list,不用time记录使用list顺序表示先后
    //利用list 的splice、insert封装好的操作！
    //但是表现反而不好hhh
    list<pair<int,int> > cache;//保存key-value键值对
    unordered_map<int,list<pair<int,int>>::iterator> hash;//保存指针索引
    int size;
public:
    LRUCache(int capacity):size(capacity){}
    int get(int key){
        auto it = hash.find(key);
        if(it == hash.end()) return -1;
        cache.splice(cache.begin(),cache,it->second);//把一个元素更新到另一个地方
        return it->second->second;
    }
    void put(int key,int value){
        auto it = hash.find(key);
        if(it !=hash.end()){
            it->second->second = value;
            return cache.splice(cache.begin(),cache,it->second);
        }
        cache.insert(cache.begin(),make_pair(key,value));
        hash[key] = cache.begin();//可体会顺序，最后是pop的
        if(cache.size() > size){
            hash.erase(cache.back().first);//back!=end
            cache.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

