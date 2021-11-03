/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
private:
    int base = 131,mod = 1000000007;
public:
    void help(vector<vector<string> >& res,vector<string>& ans,string& s,int pos){
        if(pos == s.size()){
            res.emplace_back(ans);
            return;
        }
        ans.emplace_back(string(1,s[pos])) ;
        help(res,ans,s,pos+1);
        ans.pop_back();
        int next = s.find(s[pos],pos+1);
        int left = 0,right = 0;
        int mul = 1;
        int cur = pos;
        while(next != -1){
            while(cur <= next){
                left = ((long long) left * base + (s[cur]- 'a')) % mod;
                right =(right +  (s[cur] - 'a') * (long long)mul) % mod;
                mul = (long long) mul * base % mod;
                ++cur;
            }
            if(left == right) {
                ans.push_back(s.substr(pos,cur - pos));
                help(res,ans,s,cur);
                ans.pop_back();
            }
            next = s.find(s[pos],cur);
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string > > res;
        vector<string> ans = {};
        help(res,ans,s,0);
        return res;
    }
};
// @lc code=end
