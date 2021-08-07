/*
 * @lc app=leetcode.cn id=384 lang=cpp
 *
 * [384] 打乱数组
 */

// @lc code=start
class Solution {
    vector<int> origin;
public:
    Solution(vector<int>& nums) : origin(std::move(nums)) {
        //注意这里：必须在这里写，调用STL拷贝构造函数
        //具体的这里先不求甚解了
        //move vs copy:移动不需要复制，所以很快。其实就是把自己的指针指过去，把原属主的指针指向别处。
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return origin;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> num(origin);
        for(int i = num.size() - 1;i >= 0;--i){
            int pos = rand()%(i+1);
            //注意这里应该i+1，应该有不变的机会
            swap(num[pos],num[i]);
        }
        return num;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end

