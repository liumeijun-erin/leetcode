/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */

// @lc code=start
class Solution {
public:
    //独立完成，但事先看了思路提示：sliding window
    //分析由于：left-right不可则从right开始，没有重复问题。因此left，right双指针即可求解
    //注意words中可能有重复string
    //note：明确cnt_v 是个数还是种类数！
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int> hash;
        vector<int> cnt;
        for(int i = 0;i < words.size();++i){
            if(hash.count(words[i])) ++cnt[hash[words[i]]];
            else{
                hash[words[i]] = cnt.size();
                cnt.emplace_back(1);
            }
        }
        int len = words[0].size();
        vector<int> res;
        for(int i = 0;i < len;++i){
            int left = i;
            vector<int> visited(cnt.size());
            int cnt_v = 0;
            int right = left;
            while(left + len* words.size()-1 < s.size()){
                while(right + (words.size() - cnt_v) *len - 1 < s.size()){
                    string tmp = s.substr(right,len);
                    if(hash.count(tmp)){
                        if(visited[hash[tmp]] == cnt[hash[tmp]]) {
                            while(left < right&&s.substr(left,len)!= tmp){
                                int index = hash[s.substr(left,len)];
                                --cnt_v;
                                --visited[index];
                                left += len;
                            }
                            right = right + len;
                            left = left + len;
                            break;
                        }
                        else {
                            ++visited[hash[tmp]];
                            if(visited[hash[tmp]] <= cnt[hash[tmp]]) ++cnt_v;
                            if(cnt_v == words.size()){
                                res.emplace_back(left);
                                tmp = s.substr(left,len);
                                left = left + len;
                                --visited[hash[tmp]] ;
                                --cnt_v;
                            }
                            right += len;
                        }
                    } 
                    else {
                        left = right + len;
                        right = left;
                        fill(visited.begin(),visited.end(),0);
                        cnt_v = 0;
                        break;
                    } 
                }
                
            }
            //"barfoofoobarthefoobarman"\n["bar","foo","the"]
            //"wordgoodgoodgoodbestword"\n["word","good","best","good"]
            //"aaa"\n["a","a"]
        }
        return res;
    }
};
// @lc code=end

