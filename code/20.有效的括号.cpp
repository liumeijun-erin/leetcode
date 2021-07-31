/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> ss;
        for(const char & c:s){
            //cout<<c<<endl;
            //注意使用top前一定要判断empty
            if(!ss.empty() &&( c == ')'&&ss.top() == '('||c == ']'&&ss.top() == '['||c == '}'&&ss.top() == '{')) ss.pop();
            else ss.push(c);
        }
        return ss.empty();
    }
};
// @lc code=end

