/*
 * @lc app=leetcode.cn id=363 lang=cpp
 *
 * [363] 矩形区域不超过 K 的最大数值和
 */

// @lc code=start
class Solution {
public:
    //参考了答案！！！而且很有趣
    //参考答案:优化查找顺序，固定一项然后加快查找：联想到priority_queue
    //此题根本不会，过不了
    //参考答案：
    //tip1：降维，通过固定列区间固化到一维数组(暴力一部分，优化一部分)
    //tip2：合理利用条件找target_size+api进行二分查找！set lower_bound
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(),n = matrix[0].size();
        int ans = INT_MIN;//tip
        vector<vector<int> > sum (m+1,vector<int> (n+1));
        //tip1:固定一个方向上区间降维
        for(int i = 0;i < m;++i){
            vector<int> sum(n);
            for(int j = i;j < m;++j){
                //tip2:而且这个顺序也挺重要，多到少
                for(int k = 0;k < n;++k){
                    sum[k] += matrix[j][k];
                }
                set<int> preSum{0};//tip3:这样写不用单独判断==k！
                int s = 0;
                //tip4:利用s和k的关系进行二分查找！
                for(const int&v:sum){
                    s += v;
                    if(s == k) return k;
                    auto lb = preSum.lower_bound(s - k);
                    if (lb != preSum.end()) {
                        ans = max(ans, s - *lb);//tip5:正好是答案
                    }
                    preSum.insert(s);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

