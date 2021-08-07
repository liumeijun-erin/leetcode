/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */

// @lc code=start
class Solution {
public:
    string addStrings(string num1, string num2) {
        string res = "";
        int i = num1.size()-1,j = num2.size()-1,tmp = 0;
        while(i >= 0&&j>=0){
            int a = num1[i--] - '0';
            int b = num2[j--] - '0';
            res =to_string((tmp+a+b)%10) + res;
            tmp = (tmp+a+b)/10;
            //cout<<res<<endl;
        }
        while(i >= 0){
            int a = num1[i--]-'0';
            res = to_string((tmp+a)%10)+res;
            tmp = (tmp+a)/10;
            //cout<<res<<endl;
        }
        while(j >= 0){
            int a = num2[j--]-'0';
            res = to_string((tmp+a)%10)+res;
            tmp = (tmp+a)/10;
            //cout<<res<<endl;
        }
        if(tmp) res = to_string(tmp)+res;
        return res;
    }
};
// @lc code=end

