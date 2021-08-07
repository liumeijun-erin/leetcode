/*
 * @lc app=leetcode.cn id=528 lang=cpp
 *
 * [528] 按权重随机选择
 */

// @lc code=start
class Solution {
    vector<int> sum;
public:
    Solution(vector<int>& w):sum(move(w)){
        //tip1：由答案模板可得拷贝构造函数+move移动
        //tip2：根据答案提示可以用partial_sum
        partial_sum(sum.begin(),sum.end(),sum.begin());
        //cout<<"help"<<endl;
        /*
        int n = 0;
        for(const int& num:nums){
            n += num;
            sum.emplace_back(n);
        }*/
    }
    int pickIndex() {
        int index  = rand()%sum.back() + 1;
        //int index = round(1.0*rand()/RAND_MAX*sum.back()) + 1;
        //tip3细节：这里一定要加一，否则首尾的比例不对！
        //tip4：且不要用round否则比例也不对
        //暂不深究
        //cout<<round(rand()*1.0/RAND_MAX*sum.back())<<endl;
        //cout<<round(1.0*rand()/RAND_MAX*sum.back())<<endl;
        //cout<<int(rand()*1.0/5*6)<<endl;
        //cout<<int(1.0*rand()/5*6)<<endl;
        /*for(int i = 0;i < sum.size();++i){
            if(index <= sum[i]) return i;
        }*/
        //tip5答案可得：可以利用组件函数：不仅方便，而且快好多！
        return lower_bound(sum.begin(),sum.end(),index) - sum.begin();
        //cout<<"help2"<<endl;
        
        return -1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end

