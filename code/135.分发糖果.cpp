/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        //审题：ratings固定不能改变
        //审题：分数相同的好像可以低。
        //思路：毕竟重要的都是相邻的。符合最优子结构。
        //思路：贪心思想的另一种应用左右方向每个方向都保证不低于相邻
        //个人小结：贪心->将全局最优问题缩小到满足局部限制
        //tip1:可用accumulate累加求和，在头文件#include<numeric>里
        //int res = ratings.size();
        vector<int> cnt (ratings.size());
        for(int i = 1;i < ratings.size();++i){
            if(ratings[i] > ratings[i-1]){
                cnt[i] = cnt[i - 1] + 1;
            }
        }
        for(int i = ratings.size() - 2;i >= 0;--i){
            if(ratings[i] > ratings[i+1]){
                cnt[i] = max(cnt[i + 1] + 1,cnt[i]);
            }
        }
        /*for(const int& i:cnt){
            res += i;
        }
        return res;*/
        return accumulate(cnt.begin(),cnt.end(),ratings.size());
    }
};
// @lc code=end

