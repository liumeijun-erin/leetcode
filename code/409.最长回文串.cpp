/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 */

// @lc code=start
class Solution {
public:
    int longestPalindrome(string s) {
        vector<bool> dup(52);
        for(const char& ch:s){
            if(ch<'a') dup[ch-'A'+26] = !dup[ch-'A'+26];
            else dup[ch-'a'] = !dup[ch-'a'];
        }
        int count = 0;
        for(const bool& flag:dup){
            if(flag) ++count;
        }
        return s.size()-max(0,count-1);
    }
};
// @lc code=end

