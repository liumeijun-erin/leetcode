/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 */

// @lc code=start
class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> cnt(26);
        for(const char&c:s){
            ++cnt[c-'a'];
        }
        for(const char&c:t){
            --cnt[c-'a'];
        }
        for(int i = 0;i < 26;++i){
            if(cnt[i]) return 'a'+i;
        }
        return 'a';
    }
};
// @lc code=end

