/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length()==0){
            return 0;
        }
        int pos = haystack.find(needle);
        if(pos == string::npos){
            return -1;
        }
        else return pos;
    }
};
// @lc code=end

