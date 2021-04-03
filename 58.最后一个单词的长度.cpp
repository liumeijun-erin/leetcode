/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i,lastLetter;
        for(i = s.length() - 1;i >= 0;i--){
            if(s[i] != ' ') break;
        }
        if(i >= 0){
            lastLetter = i;
        }
        else return 0;
        for(;i >= 0;i--){
            if(s[i] == ' ') break;
        }
        return lastLetter - i;
    }
};
// @lc code=end

