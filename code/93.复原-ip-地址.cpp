/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution {
public:
    void help(vector<string>& res,string tmp,int k,int pos,string& s){
        if(pos == s.size()) return;
        int cnt = s[pos]-'0';
        tmp += s[pos];
        if(k) help(res,tmp+'.',k-1,pos+1,s);
        if(s[pos]!='0'){
            for(int i = pos+1;i + k < s.size();++i){
                cnt = 10 * cnt + (s[i] - '0');
                if(cnt > 255) break;
                tmp += s[i];
                if(k) help(res,tmp+'.',k-1,i+1,s);
            }
        }
        else if(!k&&pos!=s.size()-1) return;
        if(!k){
            if(cnt <= 255) res.emplace_back(tmp);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        help(res,"",3,0,s);
        return res;
    }
};
// @lc code=end

