/*
 * @lc app=leetcode.cn id=678 lang=cpp
 *
 * [678] 有效的括号字符串
 */

// @lc code=start
class Solution {
public:
    bool checkValidString(string s) {
        //solution1-failed
        /*int cnt_left= 0,cnt_char = 0;
        for(const char& ch:s){
            if(ch == '(') ++cnt_left;
            else if(ch == '*') ++cnt_char;
            else{
                if(cnt_left) --cnt_left;
                else if(cnt_char) -- cnt_char;
                else return false;
            }
        }
        if(cnt_left) return false;
        //note1:没有考虑用*当)的情况
        return true;*/
        //策略：
        stack<int> s_left;//消掉最后的(
        queue<int> q_star;//消掉最前的*
        for(int i = 0;i < s.size();++i){
            char ch = s[i];
            if(ch == '*') q_star.emplace(i);
            else if(ch == '(') s_left.emplace(i);
            else {
                if(s_left.empty()){
                    if(q_star.empty()) return false;
                    else{
                        int index = q_star.front();
                        q_star.pop();
                        s[index] = '.';
                    }
                }
                else{
                    int index = s_left.top();
                    s_left.pop();
                    s[index] = '.';
                }
            }
        }
        if(s_left.empty()) return true;
        int cnt_left = 0;
        for(const char& ch:s){
            if(ch == '(') ++cnt_left;
            else if(ch == '*'){
                if(cnt_left) --cnt_left;
            }
        }
        if(cnt_left) return false;
        return true;
        //"("
        //"((((()(()()()*()(((((*)()*(**(())))))(())()())(((())())())))))))(((((())*)))()))(()((*()*(*)))(*)()"
    }
};
// @lc code=end

