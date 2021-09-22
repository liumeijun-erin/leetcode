/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        bool sign = false;
        int res = 0;
        int max_n = 1;
        int i;
        for(i = 0;i < 30;++i) max_n *= 2;
        max_n += max_n-1;
        i = 0;
        while(i<s.size()&&s[i]==' ') ++i;
        if(i<s.size()&&(s[i]=='-'||s[i]=='+')){
            sign = (s[i]=='-');
            ++i;
        }
        for(;i < s.size();++i){
            if(s[i]<'0'||s[i]>'9') break;
            char ch = s[i];
            if(res > 214748364||res==214748364&&(i+1<s.size()&&s[i+1]>='0'&&s[i+1]<='9'||ch>='7'&&!sign||ch>='8'&&sign)){
                if(sign) return -max_n-1;
                else return max_n;
            }
            else res = res*10+(ch-'0');
        }
        if(sign) res *= -1;
        return res;
        //"     +004500"
        //"+1"
        //"2147483646"
        //"2147483800"
    }
};
// @lc code=end

