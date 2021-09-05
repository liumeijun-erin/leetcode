/*
 * @lc app=leetcode.cn id=5849 lang=cpp
 *
 * [5849] 好子集的数目
 */

// @lc code=start
class Solution {
    vector<int> prime = {2,3,5,7,11,13,17,19,23,29};
    vector<int> clean_nums;
    map<int,int> m;
    long long x = 1000000007;
public:
//tip1:捋清思路还是挺明白的，只要稳住好好写即可
//不要纠结来纠结去含义，到底是开闭区间定好
//tip2:数据预处理很重要
//[2]
//[3,15]
//[6,8,1,8,6,5,6,11,17]
//[16,23,16,24,13,7,13,9,9,20,19,15,19,26,11,27,6,4,1,7,3,29,29,5,7,20,21,22,17,27,15,1,1,13,17,23,29,15,27,29,30,19,19,30,22,1,25,4,13,24,20,12,30,14,21,7,26,6,7,18,25]
//[10,11,5,1,10,1,3,1,26,11,6,1,1,15,1,7,22,1,1,1,1,1,23,1,29,5,6,1,1,29,1,1,21,19,1,1,1,2,1,11,1,15,1,22,14,1,1,1,1,6,7,1,14,3,5,1,22,1,1,1,17,1,29,2,1,15,10,1,5,7,1,1,1,30,1,30,1,21,10,1,1,1,1,1,2,6,5,7,3,1,1,19,29,1,7,13,14,1,5,26,19,11,1,1,1,1,1,1,1,1,22,15,1,1,13,1,17,1,1,1,13,6,1,10,1,1,17,1,1,3,14,7,17,1,13,1,1,1,1,1,11,1,1,6,1,1,1,1,1,2,1,30,2,26,1,1,14,1,26,29,30,1,13,21,1,1,14,21,1,23,1,15,23,21,1,30,19,19,1,10,23,3,3,17,22,2,26,1,11,1,23,1,1,1,15,1,1,13,1,1]
    long long backtracking(vector<int> bp,int pos){
        if(pos>= clean_nums.size()) return 1;
        int num =  clean_nums[pos],cnt = m[num];
        long long res =backtracking(bp,pos+1)%x;
        bool conflict = false;
        for(int i = 0;i < 10;++i){
            if(num%prime[i]==0){
                if(num%(prime[i]*prime[i])==0) return res;
                if(bp[i]==1) conflict = true;
                bp[i]=1;
                num = num/prime[i];
            }
        }
        if(num == 1&&!conflict) res +=  cnt*(backtracking(bp,pos+1)%x)%x;
        return res%x;
    }
    int numberOfGoodSubsets(vector<int>& nums) {
        //note:1单独处理
        //note2:超时，看来需要进行数据预处理
        long long ones = 1;
        for(const int& num:nums){
            if(num == 1) {
                ones = (ones*2)%x;
            }
            else {
                if(m.count(num)) ++m[num];
                else m[num] =1;
            }
        }
        if(m.empty()) return 0;
        for(auto it=m.begin();it!=m.end();++it){
            clean_nums.emplace_back(it->first);
        }
        vector<int> bp(10);
        return ((backtracking(bp,0)-1)*ones)%x;
    }
};
// @lc code=end

