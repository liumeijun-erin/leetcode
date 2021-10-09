/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    void help(unordered_map<char,vector<char> >& hash,vector<string>& res,string& path,string& digits,int pos){
        if(pos == digits.size()){
            res.emplace_back(path);
            return ;
        }
        for(const char&c:hash[digits[pos]]){
            path += c;
            help(hash,res,path,digits,pos+1);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,vector<char> > hash;
        int j = 0;
        for(int i = 2;i <= 9;++i){
            char c = i+'0';
            for(int k = 0;k < 3;++k) hash[c].emplace_back((j++)+'a');
            if(i == 7) hash[c].emplace_back((j++)+'a');
        }
        hash['9'].emplace_back('z');
        vector<string> res;
        string path = "";
        if(digits.empty()) return res;
        help(hash,res,path,digits,0);
        return res;
    }
};
// @lc code=end

