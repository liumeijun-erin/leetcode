/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 0,l = 0,i;
        unordered_map<char,int> hash;
        for(i = 0;i < s.size();++i){
            if(hash.count(s[i])&&hash[s[i]]>=l){
                len = max(len,i-l);
                l = hash[s[i]] + 1;
            }
            hash[s[i]] = i;
        }
        len = max(len,i-l);
        return len;
    }
};
//"abba"01
// @lc code=end

