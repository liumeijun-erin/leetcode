/*
 * @lc app=leetcode.cn id=65 lang=cpp
 *
 * [65] 有效数字
 */

// @lc code=start
class Solution {
public:
    bool isNumber(string s) {
        int type = 0;
        bool front = true;
        for(int i = 0;i < s.size();++i){
            char c = s[i];
            if(c>='0'&&c<='9') {
                front = false;
            }
            else if(c == '+'||c == '-') {
                if(!front||i==s.size()||s[i+1]!='.'&&(s[i+1]<'0'||s[i+1]>'9')) {
                    //cout<<"+- problem"<<endl;
                    return false;
                }
                front = false;
            }
            else if(c == 'e'|c == 'E'){
                if(type ==2||i==0||i==s.size()||s[i+1]!='+'&&s[i+1]!='-'&&(s[i+1]<'0'||s[i+1]>'9')) {
                    //cout<<"eE problem"<<endl;
                    return false;
                }
                type = 2;
                front = true;
            }
            else if(c=='.'){
                if(type > 0||i==0&&i==s.size()||i==0&&(s[i+1]>'9'||s[i+1]<'0')||i==s.size()-1&&(s[i-1]>'9'||s[i-1]<'0')) {
                    //cout<<". problem"<<endl;
                    return false;
                }
                type = 1;
                front = true;
            }
            else return false;
        }
        return true;
        //"e9"
        //"6+1"
        //"005047e+6"
    }
};
// @lc code=end

