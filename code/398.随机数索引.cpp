/*
 * @lc app=leetcode.cn id=398 lang=cpp
 *
 * [398] 随机数索引
 */

// @lc code=start
class Solution {
    //solution1:unordered_map有点慢
    //unordered_map<int,vector<int> > hash;
    //solution2：经典蓄水池算法:
    vector<int> num;
    //solution3：todo不保存num，只保存nums.begin(),nums.end()即可
    //tip只需要遍历的时候可以不保存整个数组，保存首尾指针即可
public:
    Solution(vector<int>& nums) :num(nums){
        /*for(int i = 0;i < nums.size();++i){
            if(hash.count(nums[i])) hash[nums[i]].emplace_back(i);
            else hash[nums[i]] = {i};
        }*/
    }
    int pick(int target) {
        //return hash[target][rand()%hash[target].size()];
        //solution2：蓄水池算法！！！
        //思路：假设当前正要读取第n个数据，则我们以1/n的概率留下该数据，否则以(n-1)/n 的概率留下前n-1个数据中的一个。而前n-1个数组留下的那个概率为1/(n-1), 因此最终留下上次n-1个数中留下的那个数的概率为[1/(n-1)]*[(n-1)/n] = 1/n,符合均匀分布的要求。
        //可以保证大数据流中只读取一遍数据，就可以等概率取到值
        int cnt=1;
        int pool=0;
        for(int i = 0;i < num.size();++i){
            if(num[i]==target){
                if(rand()%cnt==0) {
                    pool = i;
                }
                cnt++;
            }
        }
        return pool;
    }
    //solution3:参考答案，不用保存整个num，只要保存nums.begin和end即可
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
// @lc code=end

