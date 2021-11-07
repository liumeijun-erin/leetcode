/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    void help(string& tmp,int& left,int& right,int& n,vector<string>& res){
        if(left == n&&right == n) {
            res.emplace_back(tmp);
        }
        if(left > right) {
            tmp += ')';
            ++right;
            help(tmp,left,right,n,res);
            tmp.pop_back();
            --right;
        }
        if(left < n){
            tmp += '(';
            ++left;
            help(tmp,left,right,n,res);
            tmp.pop_back();
            --left;
        }
    }
    vector<string> generateParenthesis(int n) {
        int left = 0,right = 0;
        vector<string> res;
        string tmp = "";
        help(tmp,left,right,n,res);
        return res;
    }
};
// @lc code=end

