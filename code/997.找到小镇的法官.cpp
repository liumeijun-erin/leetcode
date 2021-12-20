/*
 * @lc app=leetcode.cn id=997 lang=cpp
 *
 * [997] 找到小镇的法官
 */

// @lc code=start
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // if (n == 1) return 1;
        vector<bool> truster(n+1,false);
        vector<int> trusted(n+1,0);
        int res = -1;
        for (const vector<int>& t_pair: trust) {
            trusted[t_pair[1]] += t_pair[0];
            truster[t_pair[0]] = true;
        }
        for (int i = 1;i <= n; ++i) {
            if (i + trusted[i] == n * (n+1) /2 && truster[i] == false) return i; 
        }
        return -1;
        // 特例： 1\n[]
    }
};
// @lc code=end

