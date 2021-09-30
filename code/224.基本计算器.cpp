/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 */

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        stack<char> s_oper;
        stack<int> s_num;
        int num = 0;
        for(const char&c:s){
            if(c == ' ') continue;
            if(c >= '0'&&c <= '9') {
                num = num*10 + (c-'0');
                continue;
            }
            else if(c == '('){
                s_oper.emplace(c);
                continue;
            }
            while(!s_oper.empty()&&s_oper.top()!='('){
                int num_pre = 0;
                if(!s_num.empty()){
                    num_pre = s_num.top();
                    s_num.pop();
                }
                if(s_oper.top() == '-') num = num_pre - num;
                else num = num_pre + num;
                s_oper.pop();
                if(c == ')'&&s_oper.top()=='(') s_oper.pop();
            }
            s_num.emplace(num);
            num = 0;
            if(c == '+'||'-') s_oper.emplace(c);
        }
        if(!s_oper.empty()){
            int num_pre = 0;
            if(!s_num.empty()) {
                num_pre = s_num.top();
                s_num.pop();
            }
            if(s_oper.top() == '-') s_num.emplace(num_pre-num);
            else s_num.emplace(num_pre+num);
        }
        return s_num.top();
    }
};
// @lc code=end

