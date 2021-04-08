/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
public:
    int toNum(string str){
        //tip1:dont forget '-'
        int num = 0;
        int sign = 1;
        if(str[0] == '-'){
            sign = -1;
            str.erase(0,1);
        }
        for(int i = 0;i < str.length();i++){
            num = num * 10 + str[i] - '0';
        }
        return num * sign;
    }
    int evalRPN(vector<string>& tokens) {
        //way1
        //tip2:C++ built-in func :atoi(token.c_str()
        stack<int> s;
        int a,b;
        for(int i = 0;i < tokens.size();i++){
            /*if(tokens[i] == "*" ||tokens[i] == "+"||tokens[i] == "/"||tokens[i] == "-" ){
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                if(tokens[i] =="*") s.push(a*b);
                else if(tokens[i] =="/") s.push(a/b);
                else if(tokens[i] == "-") s.push(a-b);
                else s.push(a+b);
            }
            else{
                //s.push(toNum(tokens[i]));
                s.push(atoi(tokens[i].c_str()));
            }*/
            //tip3:much faster
            if(tokens[i][0] >= '0' && tokens[i][0] <= '9' ||tokens[i] != "-" && tokens[i][0] == '-'){
                //s.push(atoi(tokens[i].c_str()));
                s.push(toNum(tokens[i]));
                continue;
            }
            b = s.top();
            s.pop();
            a = s.top();
            s.pop();
            if(tokens[i] == "*"){
                s.push(a*b);
            }
            else if(tokens[i] =="/"){
                s.push(a/b);
            }
            else if(tokens[i] == "+"){
                s.push(a+b);
            }
            else s.push(a - b);
        }
        return s.top();
    }
    /*int evalRPN(vector<string>& tokens) {
        //tip4:way2 use vector to reduce opertation times
        vector<int> nums((tokens.size() + 1)/2);
        int index = 0;
        for(int i = 0;i < tokens.size();i++){
            if(tokens[i][0] <= '9' && tokens[i][0] >= '0' || tokens[i][0] =='-' && tokens[i] != "-"){
                nums[index++] = atoi(tokens[i].c_str());
                continue;
            }
            if(tokens[i] == "*"){
                nums[index - 2 ] = nums[index - 2] * nums[index-1];
            }
            else if(tokens[i] == "/"){
                nums[index - 2 ] = nums[index - 2] / nums[index-1];
            }
            else if(tokens[i] == "-"){
                nums[index - 2 ] = nums[index - 2] - nums[index -1];
            }
            else  nums[index - 2 ] = nums[index - 2] + nums[index-1];
            index--;
        }
        return nums[--index];
    }*/
};
// @lc code=end

