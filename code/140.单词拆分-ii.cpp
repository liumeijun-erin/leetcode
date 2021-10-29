/*
 * @lc app=leetcode.cn id=140 lang=cpp
 *
 * [140] 单词拆分 II
 */

// @lc code=start
class Solution {
public:
    //传引用快好多好多好多！
    void help(string& s, set<string>& wordSet,string& tmp,int pos,vector<string>& res){
        if(pos == s.size()) {
            tmp.pop_back();
            res.emplace_back(tmp);
            return ;
        }
        for(int i = pos+1;i <= s.size();++i){
            string word = s.substr(pos,i-pos);
            string pre = tmp;
            tmp +=  word;
            tmp += ' ';
            if(wordSet.count(word)) help(s,wordSet,tmp,i,res);
            tmp = pre;
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        set<string> wordSet;
        for(const string& ss:wordDict) wordSet.insert(ss);
        string tmp = "";
        help(s,wordSet,tmp,0,res);
        return res;
    }
};
// @lc code=end

