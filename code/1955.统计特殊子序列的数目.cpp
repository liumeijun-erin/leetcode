/*
 * @lc app=leetcode.cn id=1955 lang=cpp
 *
 * [1955] 统计特殊子序列的数目
 */

// @lc code=start
class Solution {
public:
    // 审题：不一定数目相同
    // 动态规划很对只是没敢写, 按构造往上塞的思路
    int countSpecialSubsequences(vector<int>& nums) {
        int cnt[3] = {0};
        const int mod = 1000000007;
        for (const int& num: nums) {
            switch (num) {
                // 参考答案这里改进：使用前缀都是0的个数而不是0的个数，省去了算幂的过程
                // case 0: ++cnt[0];break;
                // note: 注意
                这里位移操作一定需要()
                case 0: cnt[0] = (cnt[0] << 1)%mod + 1; break;
                case 1: cnt[1] = ((cnt[1] << 1)%mod + cnt[0])%mod; break;
                case 2: cnt[2] = ((cnt[2] << 1)%mod + cnt[1])%mod;
            }
        }
        return cnt[2];
    }
};
// @lc code=end

