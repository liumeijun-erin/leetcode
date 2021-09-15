/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        stack<int> sn;
        stack<string> ss;
        string res = "";
        string tmp = "";
        for(int i = 0;i < s.size();++i){
            if(s[i]>='0'&&s[i]<='9'){
                int n = 0;
                while(i < s.size()&&s[i]>='0'&&s[i]<='9') n = 10*n + (s[i++]-'0');
                sn.emplace(n);
                ss.emplace(tmp);
                tmp = "";
            }
            else if(s[i] ==']'){
                int n = sn.top();
                sn.pop();
                string tmp_all = ss.top();
                ss.pop();
                while(n--) tmp_all += tmp;
                tmp = tmp_all;
                if(ss.empty()){
                    res += tmp;
                    tmp = "";
                }
            }
            else{
                if(ss.empty()) res += s[i];
                else tmp += s[i];
            }
        }
        return res;
        //"3[a2[c]]"考虑全面，由于有嵌套存在，string也得建栈
    }
};
// @lc code=end

