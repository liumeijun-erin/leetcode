/*
 * @lc app=leetcode.cn id=397 lang=cpp
 *
 * [397] 整数替换
 */

// @lc code=start
class Solution {
public:
    int help(unordered_map<int,int>& hash, int n) {
        if(hash.count(n)) return hash[n];
        int res = -1;
        if (n%2) {
            if(n == 2147483647) res = min(help(hash,n-1) + 1,help(hash, 1073741824) +2);
            else res = min(help(hash,n+1), help(hash,n-1)) + 1;
        }
        else{
            res = help(hash, n/2) + 1;
        }
        hash[n] = res;
        return res;
    }
    int integerReplacement(int n) {
        //200000000超时
        unordered_map<int,int> hash;
        hash[1] = 0;
        return help(hash,n);
    }
};
// @lc code=end

