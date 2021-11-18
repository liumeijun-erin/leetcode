/*
 * @lc app=leetcode.cn id=386 lang=cpp
 *
 * [386] 字典序排数
 */

// @lc code=start
class Solution {
public:
    void help(int& n, int& tmp, vector<int>& res) {
        if(tmp > n) return ;
        if(tmp != 0) {
            res.emplace_back(tmp);
            tmp *= 10;
            help(n, tmp, res);
        }
        for (int i = 1;i <= 9; ++i) {
            tmp += 1;
            help(n, tmp, res);
        }
        tmp -= 9;
        tmp /= 10;
    }
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        int tmp = 0;
        help(n, tmp, res);
        return res;
    }
};
// @lc code=end

