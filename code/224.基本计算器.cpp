/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 */

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        //solution1:加入0解决无符号数，其他压栈弹栈,表现不好
        //solution2:参考答案！！！！结合题目特性转化：有无括号无所谓+可以不考虑二元操作视为有符号数的和！
        //"- (3 + (4 + 5))" 考虑这种情况，使用一个stack记录当前num对应符号即可！
        /*stack<int> s_num;
        stack<char> s_oper;
        int num;
        bool preNum = false;
        for(int i = 0;i < s.size();++i){
            if(s[i] == ' ') continue;
            else if(s[i] == '('){
                s_oper.emplace(s[i]);
                preNum = false;
                continue;
            }
            else if(s[i] == '+'||s[i] == '-'){
                s_oper.emplace(s[i]);
                if(!preNum) {
                    s_num.emplace(0);
                    preNum = false;
                }
                continue;
            }
            else if(s[i] >= '0'&& s[i]<= '9') {
                num = 0;
                while(i < s.size()&&s[i] >= '0'&& s[i]<= '9'){
                    num = num*10 + (s[i]-'0');
                    ++i;
                }
                s_num.emplace(num);
                --i;
            }
            else if(s[i]==')') {
                s_oper.pop();
            }
            if(!s_oper.empty()&&s_oper.top()!='('){
                int b = s_num.top();
                s_num.pop();
                int a = s_num.top();
                s_num.pop();
                if(s_oper.top()=='+') num = a+b;
                else num = a-b;
                s_oper.pop();
                s_num.emplace(num);
            }
            preNum = true;
        }
        return s_num.top();*/
        //"1-(-2)"
        //note:考虑这种带符号数
        //solution2:
        //参考答案使用一个栈记录符号即可！每层对应一个括号
        // bit tricky :"- (3 + (4 + 5))"
        stack<int> s_oper;
        s_oper.emplace(1);
        int sign = 1;
        int sum = 0;
        for(int i = 0;i < s.size();++i){
            if(s[i] >= '0'&&s[i] <= '9'){
                int num = 0;
                while(i<s.size()&&s[i] >= '0'&&s[i] <= '9'){
                    num = num*10 + (s[i++]-'0');
                }
                --i;
                sum += num*sign;
                sign = 1;
            }
            else if(s[i] == '-') sign = -s_oper.top();
            else if(s[i] == '+') sign = s_oper.top();
            else if(s[i] == '('){
                s_oper.emplace(sign);
            }
            else if(s[i]==')'){
                s_oper.pop();
            }
        }
        return sum;
    }
};
// @lc code=end

