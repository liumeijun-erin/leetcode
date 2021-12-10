/*
 * @lc app=leetcode.cn id=748 lang=cpp
 *
 * [748] 最短补全词
 */

// @lc code=start
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        unordered_map<char,int> hash;
        int minlen = 0;
        for (char& c: licensePlate) {
            if (c >= 'A' && c <= 'Z') c += 'a' - 'A';
            if (c > 'z' || c < 'a') continue;
            if (hash.count(c)) ++hash[c];
            else hash[c] = 1;
            ++minlen;
        }
        vector<pair<int,int> > len_id;
        for (int i = 0; i < words.size(); ++i) {
            len_id.emplace_back(make_pair(words[i].size(),i));
        }
        sort(len_id.begin(), len_id.end(), [](pair<int,int>& p1, pair<int,int>& p2){
            if (p1.first == p2.first) return p1.second < p2.second;
            return p1.first < p2.first;
        });
        string res ;
        for (pair<int,int>& p: len_id) {
            if (p.first < minlen) continue;
            res = words[p.second];
            vector<int> cnt (26,0);
            for (const char&c : res) {
                ++cnt[c-'a'];
            }
            bool contains = true;
            for (auto it = hash.begin(); it!= hash.end(); ++it) {
                if(cnt[it->first-'a'] < it->second) {
                    contains = false;
                    break;
                }
            }
            if(contains) break;
        }
        return res;
        //"tR28607"\n["present","fall","make","change","everything","performance","owner","beat","name","serve"]
    }
};
// @lc code=end

