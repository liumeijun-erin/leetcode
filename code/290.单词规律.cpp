/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 */

// @lc code=start
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> hash(26,"");
        unordered_set<string> ss;
        int i = 0,j = i;
        for(const char& ch:pattern){
            while(i < s.size()&&s[i]==' ') ++i;
            if(i == s.size()) return false;
            j = i;
            while(j<s.size()&&s[j]!=' ') ++j;
            string tmp = s.substr(i,j-i);
            i = j;
            if(hash[ch-'a'] == ""){
                if(ss.count(tmp)) return false;
                ss.insert(tmp);
                hash[ch-'a'] = tmp;
            }
            else if(hash[ch-'a']!=tmp) return false;
        }
        if(j!=s.size()) return false;
        return true;
    }
    //"aaa"\n"aa aa aa aa"
};
// @lc code=end

