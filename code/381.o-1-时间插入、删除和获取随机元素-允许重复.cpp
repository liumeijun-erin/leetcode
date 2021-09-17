/*
 * @lc app=leetcode.cn id=381 lang=cpp
 *
 * [381] O(1) 时间插入、删除和获取随机元素 - 允许重复
 */

// @lc code=start
class RandomizedCollection {
    //这种方法节约了一定的空间
    //对比432，146增加和删除变化相对不多，且要求返回随机数vectorbetter
    //注意用unordered_set，结果75/91
    //尝试使用只存第一个int empty_pos使用数组链表，使用num.first=-1标空
    //审题，有可能insert-1所以不能用first==-1表标空，
    unordered_map<int,int> index;
    vector<pair<int,int> > num;    
    unordered_set<int> empty_pos;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        int pos;
        if(!empty_pos.empty()) {
            pos = *(empty_pos.begin());
            empty_pos.erase(empty_pos.begin());
            num[pos].first = val;
        }
        else{
            pos = num.size();
            num.emplace_back(make_pair(val,-1));
        }
        if(index.count(val)){
            num[pos].second = index[val];
            index[val] = pos;
            return false;
        }
        index[val] = pos;
        return true;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(!index.count(val)) return false;
        int pos = index[val];
        index[val] = num[index[val]].second;
        if(index[val] == -1) index.erase(val);
        num[pos] = make_pair(-1,-1);
        empty_pos.emplace(pos);
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int pos = rand()%num.size();
        while(empty_pos.count(pos)){
            pos = rand()%num.size();
        }
        return num[pos].first;
    }
};
//["RandomizedCollection","insert","remove","insert"]\n[[],[1],[1],[1]]
//["RandomizedCollection","insert","insert","remove","insert","remove","getRandom"]\n[[],[0],[1],[0],[2],[1],[]]
//["RandomizedCollection","insert","remove","insert","remove","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom"]\n[[],[0],[0],[-1],[0],[],[],[],[],[],[],[],[],[],[]]

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

