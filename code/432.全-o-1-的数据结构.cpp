/*
 * @lc app=leetcode.cn id=432 lang=cpp
 *
 * [432] 全 O(1) 的数据结构
 */

// @lc code=start
class AllOne {
    //指针写的更谨慎一点，不能太混乱
    //参考146重写，利用互换而不是删除插入，这样指针稳定些
    //终于过了但是麻烦死
    //耐心一些！
    list<string> bucket;
    unordered_map<string,pair<int,list<string>::iterator> > hash;
    unordered_map<int,pair<list<string>::iterator,list<string>::iterator> > index;
public:
    /** Initialize your data structure here. */
    AllOne() {

    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if(!hash.count(key)){
            bucket.insert(bucket.begin(),key);
            hash[key] = make_pair(1,bucket.begin());
            if(index.count(1)) index[1].first = bucket.begin();
            else index[1] = make_pair(bucket.begin(),bucket.begin());
        }
        else{
            list<string>::iterator it = index[hash[key].first].second;
            hash[*it] = make_pair(hash[key].first,hash[key].second);
            (*(hash[key].second)).swap(*it);
            hash[key] = make_pair(hash[key].first+1,it);
            if(index.count(hash[key].first)){
                index[hash[key].first].first = it;
            }
            else{
                index[hash[key].first] = make_pair(it,it);
            }
            if(it==index[hash[key].first-1].first) index.erase(hash[key].first-1);
            else index[hash[key].first-1].second = --it;
        }
    }
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        list<string>::iterator it = index[hash[key].first].first;
        hash[*it] = make_pair(hash[key].first,hash[key].second);
        swap(*(hash[key].second),(*it));
        hash[key] = make_pair(hash[key].first-1,it);
        if(it==index[hash[key].first+1].second) index.erase(hash[key].first+1);
        else {
            index[hash[key].first+1].first = ++it; 
            --it;
        } 
        if(hash[key].first == 0){
            hash.erase(key);
            bucket.erase(bucket.begin());
        }
        else{
            if(index.count(hash[key].first)){
                index[hash[key].first].second = it;
            }
            else{
                index[hash[key].first] = make_pair(it,it);
            }
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if(bucket.empty()) return "";
        return bucket.back();
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if(bucket.empty()) return "";
        return bucket.front();
    }
};
//["AllOne","inc","inc","inc","inc","getMaxKey","inc","inc","inc","dec","inc","inc","inc","getMaxKey"]\n[[],["hello"],["goodbye"],["hello"],["hello"],[],["leet"],["code"],["leet"],["hello"],["leet"],["code"],["code"],[]]
//["AllOne","inc","inc","inc","inc","inc","inc","dec", "dec","getMinKey","dec","getMaxKey","getMinKey"]\n[[],["a"],["b"],["b"],["c"],["c"],["c"],["b"],["b"],[],["a"],[],[]]
/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
// @lc code=end

