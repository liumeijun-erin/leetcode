/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        //递归方法超时
        /*if(s.size() == 0) return 1;
        else if(s[0] == '0') return 0;
        else if(s.length()==1) return 1;
        int res = numDecodings(s.substr(1,s.length()-1));
        if(s[0]=='1'||s[0]=='2'&&s[1]<='6'){
            res += numDecodings(s.substr(2,s.length()-2));
        }
        return res;*/
        //"111111111111111111111111111111111111111111111"
        //自底向上动态规划
        vector<int> res(s.size());
        for(int i = s.size()-1;i >=0;--i){
            if(s[i] == '0') {
                if(i-1<0) return 0;
                else if(s[i-1]>='3'||s[i-1]=='0') return 0;
                if(i == s.size() - 1) s[i-1] += 1;
                else s[i-1] += s[i+1];
            }
            else if(s[i] >= '7'){
                if(i == s.size() - 1) s[i] = 1;
                else s[i] = s[i-1];
            }
            else{
                if(i == s.size() - 1) s[]
            }
        }
    }
};
// @lc code=end

