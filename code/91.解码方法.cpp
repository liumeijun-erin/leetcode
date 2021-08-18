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
        if(s[0] == '0') return 0;
        res[0] = 1;
        for(int i = 1;i < s.size();++i){
            if(s[i] == '0'){
                //note:if()不能检测'0'！!
                if(s[i-1]=='0'||s[i-1]>='3') return 0;
                if(i == 1) res[i] = 1;
                else res[i] = res[i-2];
            }
            else if((s[i-1]=='1')||(s[i]>='1'&&s[i]<='6'&&s[i-1] =='2')){
                if(i == 1) res[i] = res[i-1] + 1;
                else res[i] = res[i-2] + res[i-1];
            }
            else{
                res[i] = res[i-1];
            }
        }
        for(const int& r:res){
            cout<<r<<" ";
        }
        return res[s.size()-1];
    }
};
// @lc code=end

