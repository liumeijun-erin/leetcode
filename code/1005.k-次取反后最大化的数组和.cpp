/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

// @lc code=start
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        vector<int> tmp_neg;
        int pos_min = 101;
        int res_pos = 0;
        for (const int& n:nums) {
            if (n<0) tmp_neg.emplace_back(-n);
            else {
                res_pos += n;
                pos_min = min(pos_min, n);
            }
        }
        sort(tmp_neg.begin(), tmp_neg.end(),[](int& a, int& b){return a > b;});
        for (int i = 0;i < tmp_neg.size();++i) {
            if (k>0) {
                res_pos += tmp_neg[i];
                --k;
            }
            else res_pos -= tmp_neg[i];
        }
        if (k%2) {
            if(!tmp_neg.empty()) pos_min = min(pos_min, tmp_neg[tmp_neg.size()-1]);
            res_pos -= 2*pos_min;
        }
        return res_pos;
        //[2,-3,-1,5,-4]\n2
    }
};
// @lc code=end

