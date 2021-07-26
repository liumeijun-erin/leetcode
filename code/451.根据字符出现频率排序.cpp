/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */

// @lc code=start
class Solution {
public:
    string frequencySort(string s) {
        long long count[62] = {0};
        for(const char c:s){
            if(c>='a' && c<='z') ++count[c-'a'];
            else if(c>='A' && c<='Z') ++count[c-'A'+26];
            else ++count[52+c-'0'];
        }
        map<long long,vector<char>,greater<long long>> bucket;
        for(int i = 0; i < 62;i++){
            if(count[i]){
                if(i < 26){
                    bucket[count[i]].push_back(i + 'a');
                }
                else if(i < 52){
                    bucket[count[i]].push_back(i - 26+ 'A');
                }
                else{
                    bucket[count[i]].push_back(i - 52 + '0');
                }
            }
        }
        string res = "";
        for(const auto p:bucket){
            for(char ch:p.second){
                for(long long k = 0;k < p.first;k++){
                    res += ch;
                }
            }
        }
        return res;
    }
};
// @lc code=end

