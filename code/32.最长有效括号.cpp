/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        vector<bool> fixed(s.size());
        stack<int> leftq;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') leftq.emplace(i);
            else if(!leftq.empty()){
                fixed[leftq.top()] = 1;
                leftq.pop();
                fixed[i] = 1;
            }
        }
        int pos = 0;
        int res = 0;
        while (pos < fixed.size()) {
            while(pos < fixed.size() && fixed[pos] == 0) ++pos;
            int pre = pos;
            while(pos < fixed.size() && fixed[pos] == 1) ++pos;
            res = max(pos - pre, res);
        }
        //"()(()"
        //")(((((()())()()))()(()))("
        //"((()()(()((()"
        return res;
    }
};
// @lc code=end
