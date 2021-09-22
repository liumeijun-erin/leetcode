/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
class Solution {
public:
    //表现不好：todo错位相加可以不加0而是直接从错位的第一位开始加
    void add(string& num1,string& num2){
        if(num1.size()<num2.size()) swap(num1,num2);
        int i = num1.size()-1,j = num2.size()-1;
        int t = 0;
        while(j>=0){
            char c = (num1[i]-'0'+num2[j]-'0'+t)%10+'0';
            t = (num1[i]-'0'+num2[j]-'0'+t)/10;
            num1[i] = c;
            --i;
            --j;
        }
        while(i>=0&&t) {
            char c = (num1[i]-'0'+t)%10+'0';
            t = (num1[i]-'0'+t)/10;
            num1[i] = c;
            --i;
        }
        if(t) num1 = "1"+num1;
    }
    string multiplyByBit(string& num,int a){
        string res = "";
        int t = 0;
        for(int i = num.size()-1;i>=0;--i){
            res.push_back(((num[i]-'0')*a+t)%10 + '0');
            t = ((num[i]-'0')*a+t)/10;
        }
        if(t) res.push_back(t+'0');
        reverse(res.begin(),res.end());
        return res;
    }
    string multiply(string num1, string num2) {
        if(num1[0]=='0'||num2[0]=='0') return "0";
        string tmp = "";
        string res = "";
        for(int i = num2.size()-1;i>=0;--i){
            string tmp_res = multiplyByBit(num1,num2[i]-'0') + tmp;
            add(res,tmp_res);
            tmp = tmp+ "0";
        }
        return res;
    }
};
// @lc code=end

