/*
 * @lc app=leetcode.cn id=372 lang=cpp
 *
 * [372] 超级次方
 */

// @lc code=start
class Solution {
public:
    int superPow(int a, vector<int>& b) {
        if(a == 1) return 1;
        const int mod = 1337;
        int res = 1;
        int pos = b.size()-1;
        for(int i = b.size()-1;i >= 0;--i){
            for(int j = 0;j < b[i];++j) res = (long long) res * a % mod;
            int mul = 1;
            for(int j = 0;j < 10;++j) mul = (long long) mul * a % mod;
            a = mul;
        }
        return res;
    }
};
// @lc code=end

