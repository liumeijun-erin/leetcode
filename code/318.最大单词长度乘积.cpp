/*
 * @lc app=leetcode.cn id=318 lang=cpp
 *
 * [318] 最大单词长度乘积
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> p(26,1);
        for(int i = 1;i < 26;++i) p[i] <<= 1;
        vector<int> record(words.size(),0);
        int maxn = 0;
        for(int i = 0;i < words.size();++i){
            string word = words[i];
            for(const char& ch:word){
                if(p[ch] == 0){
                    p[ch] = 1;
                    record[word] += p[ch-'a'];
                } 
            }
            if(i == 0) continue;
            for(int j = 0;j < i;++j){
                if(record[word]&record[words[j]] == 0){
                    maxn = max(maxn,word.size()*words[j].size());
                }
            }
        }
        return maxn;
    }
};
// @lc code=end

 