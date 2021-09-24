/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */

// @lc code=start
class Solution {
public:
    //审题需要组合顺序
    //dfs超时，所以需要dp
    //这里思路即为构造而非筛选
    //!!!!这里注意两种遍历的顺序很重要！只要换过来即可保留顺序！
    //如果调过来则各因数顺序一定！
    int combinationSum4(vector<int>& nums, int target) {
        vector<long long> cnt(target+1);
        cnt[0] = 1;
        for(int i = 0;i <=target;++i){
            for(const int& num:nums){
                if(i < num) continue;
                if(cnt[i] >= 2147483647) continue;
                cnt[i] +=  cnt[i-num];
            }
        }
        return cnt[target];
    }
};
// @lc code=end

