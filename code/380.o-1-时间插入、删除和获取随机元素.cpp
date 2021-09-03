/*
 * @lc app=leetcode.cn id=380 lang=cpp
 *
 * [380] O(1) 时间插入、删除和获取随机元素
 */

// @lc code=start
class RandomizedSet {
    //solution1:
    /*unordered_map<int,int> m;
    vector<int> gap;
    vector<int> nums;*/
    //solution2:参考答案：利用置换优化--不用两个数组，而是将空白的置于后端，记录数组长度即可
    unordered_map<int,int> m;
    int size;
    vector<int> nums;
public:
    RandomizedSet():size(0) {

    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(m.count(val)) return false;
        /*if(gap.empty()){
            m[val] = nums.size();
            nums.emplace_back(val);
        }
        else{
            nums[gap.back()] = val;
            m[val] = gap.back();
            gap.pop_back();
        }*/
        if(nums.size()==size){
            nums.emplace_back(val);
        }
        else nums[size] = val;
        m[val] = size;
        ++size;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(!m.count(val)) return false;
        --size;
        m[nums[size]] = m[val];
        //这行别忘
        swap(nums[m[val]],nums[size]);
        m.erase(val);
        /*gap.emplace_back(m[val]);
        m.erase(val);*/
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        //error这样的话会有很多堆积在第一个非empty
        /*int index  = rand()%nums.size();
        while(!m.count(nums[index])){
            index  = rand()%nums.size();
        }*/
        int index = rand()%size;
        return nums[index];
    }
};
//["RandomizedSet","insert","insert","remove","insert","remove","getRandom"]\n[[],[0],[1],[0],[2],[1],[]]

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

