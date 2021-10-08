/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 */

// @lc code=start
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<long long> s_hash;
        unordered_set<long long> res_hash; 
        unordered_map<char,int> c_hash;
        c_hash['A'] = 1;
        c_hash['C'] = 2;
        c_hash['G'] = 3;
        c_hash['T'] = 4;
        vector<string> res;
        long long num = 0,len = 1000000000;
        for(int i = 0;i< 10;++i){
            num= 10*num + c_hash[s[i]];
        }
        s_hash.emplace(num);
        for(int i = 10;i <s.size();++i){
            num -= c_hash[s[i-10]]*len;
            num *= 10;
            num += c_hash[s[i]];
            if(s_hash.count(num)){
                if(!res_hash.count(num)){
                    res.emplace_back(s.substr(i-10+1,10));
                    res_hash.emplace(num);
                }
            }
            else s_hash.insert(num);
        }
        return res;
    }
};
// @lc code=end

