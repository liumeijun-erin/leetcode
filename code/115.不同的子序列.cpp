/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
class Solution {
public:
    // todo:参考答案二维动态规划
    // s1-dfs超时，稍微改进一点点
    // void help(unordered_map<char,vector<int>>& hash, string& t, int pre, int pos, int& cnt) {
    //     if (pos == t.size()) {
    //         ++cnt ;
    //         return ;
    //     }
    //     for(const int& id:hash[t[pos]]) {
    //         if(pre >= id) continue;
    //         help(hash, t, id, pos+1 , cnt);
    //     }
    // }

    // int numDistinct(string s, string t) {
    //     unordered_map<char,vector<int>> hash;
    //     for (const char& c: t) {
    //         hash[c] = vector<int> {};
    //     }
    //     for (int id = 0; id < s.size(); ++id) {
    //         if (hash.count(s[id])) {
    //             hash[s[id]].emplace_back(id);
    //         }
    //     }
    //     int cnt = 0;
    //     help(hash, t, -1, 0, cnt);
    //     return cnt;
    // }
    // "adbdadeecadeadeccaeaabdabdbcdabddddabcaaadbabaaedeeddeaeebcdeabcaaaeeaeeabcddcebddebeebedaecccbdcbcedbdaeaedcdebeecdaaedaacadbdccabddaddacdddc"\n"bcddceeeebecbc"
    //s2
    int numDistinct(string s, string t) {
        if(s.size() < t.size()) return 0;
        vector<int> cnt(t.size() + 1);
        cnt[0] = 1;
        int base = 2147483647;
        unordered_map<char,vector<int>> hash;
        for (int i = 0; i < t.size(); ++i) {
            if(!hash.count(t[i])) hash[t[i]] = vector<int> {i+1};
            else hash[t[i]].emplace_back(i + 1);
        }
        for (const char& c:s) {
            //cout<<c<<":";
            for (int i = hash[c].size()-1; i >= 0; --i) {
                int id = hash[c][i];
                if(cnt[id-1]) {
                    if((long long)cnt[id-1] + cnt[id] < base) {
                        cnt[id] += cnt[id-1] ;
                    }
                }
                //cout<<id<<" ";
            }
            //cout<<endl;
        }
        return cnt[t.size()];
    }
};
// @lc code=end

