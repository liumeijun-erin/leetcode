/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    void help(vector<string>& res, int left, int right, string& tmp, int& n) {
        if (tmp.size() == 2*n) res.emplace_back(tmp);
        else {
            if (left > right) {
                tmp += ')';
                help(res, left, right + 1, tmp, n);
                tmp.pop_back();
            }
            if (left < n) {
                tmp += '(';
                help(res,left+1, right,tmp, n);
                tmp.pop_back();
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string tmp = "";
        help(res, 0, 0, tmp, n);
        return res;
    }
};
// @lc code=end

