/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */

// @lc code=start
class Solution {
public:
    // solution1-独立完成，但事先看了思路提示：sliding window O(s.size()*len)
    // note1：将句子分为长度为len的words共有0-len-1共len种分法，然后按分好words的id进行遍历
    // note2：双指针left,right。原则:left-right不可则从right开始，没有重复问题。因此left，right双指针即可求解
    //注意words中可能有重复string
    //note：明确cnt_v 是个数还是种类数！
    // 分析：表现最右：使用unordered_map既可以提前终止break剪枝；也可利用了区间内都是word的关系。
    // 一旦right不行直接从right开始
    // tips：定长分段！！！按起始点0-len-1分
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

    //solution2-由于定长len, 所以维护cnt个rk结果依次比较比较 O(s.size()*cnt)
    // 问题在于虽然用了robinkarp 匹配字符串比依次unordered_map快，但是不能提前break
    // int toNum(const string& word, int start, int end) {
    //     int res = 0;
    //     for (int i = start; i <end ; ++i) {
    //         res = (res * mul + (word[i]-'a')) % mod;
    //     }
    //     return res;
    // }
    // vector<int> findSubstring(string s, vector<string>& words) {
    //     vector<int> res;
    //     int len = words[0].size(),cnt = words.size();
    //     unordered_map<int,int> hash;
    //     for (const string& w: words) {
    //         int num = toNum(w,0,len);
    //         if (hash.count(num)) ++hash[num];
    //         else hash[num] = 1;
    //     }  
    //     vector<int> nums(cnt,0);
    //     for (int i = 0; i < cnt; ++i) {
    //        nums[i] = toNum(s,len*i,len*(i+1));
    //     }
    //     long long con = 1;
    //     for (int i = 1; i < len; ++i) {
    //         con = (con * mul) % mod;
    //     }
    //     for (int i = 0; i + cnt*len-1 < s.size(); ++i) {
    //         bool qualified = true;
    //         unordered_map<int,int> tmp(hash);
    //         for (int j = 0; j < cnt; ++j) {
    //             if (i > 0) {
    //                 // nums[j] = toNum(s,len*j+i,len*(j+1)+i);
    //                 nums[j] = (nums[j] - (s[i+j*len-1]-'a')*con + mod) % mod;
    //                 nums[j] = (nums[j] + mod) % mod;
    //                 nums[j] = (nums[j] * mul) % mod;
    //                 nums[j] = (nums[j] + (s[i+(j+1)*len-1]-'a'))%mod;
    //             }
    //             if (!tmp.count(nums[j]) || tmp[nums[j]] == 0)  {
    //                 qualified = false;
    //                 // break; 注意这个break 一定不能有，影响后面的计算
    //             }
    //             --tmp[nums[j]];
    //         }
    //         if(qualified) res.emplace_back(i);
    //     }
    //     return res;
    // }

    //solution3-不用robin-karp 改用unordered_map
    // 没有solution1表现好，没有利用上left-right关系
    // vector<int> findSubstring(string s, vector<string>& words) {
    //     vector<int> res;
    //     int len = words[0].size(),cnt = words.size();
    //     unordered_map<string,int> hash;
    //     for (const string& w: words) {
    //         if (hash.count(w)) ++hash[w];
    //         else hash[w] = 1;
    //     }  
    //     vector<int> nums(cnt,0);
    //     for (int i = 0; i + cnt*len-1 < s.size(); ++i) {
    //         bool qualified = true;
    //         unordered_map<string,int> tmp(hash);
    //         for (int j = 0; j < cnt; ++j) {
    //             string str_j = s.substr(len*j+i,len);
    //             if (!tmp.count(str_j) || tmp[str_j] == 0)  {
    //                 qualified = false;
    //                 break; 
    //             }
    //             --tmp[str_j];
    //         }
    //         if(qualified) res.emplace_back(i);
    //     }
    //     return res;
    // }

};
// @lc code=end

