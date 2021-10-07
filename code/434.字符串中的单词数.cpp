/*
 * @lc app=leetcode.cn id=434 lang=cpp
 *
 * [434] 字符串中的单词数
 */

// @lc code=start
class Solution {
public:
    int countSegments(string s) {
        bool cnt = true;
        int res = 0;
        for(const char& c:s){
            if(c == ' ') cnt = true;
            else if(cnt) {
                cnt = false;
                ++res;
            }
        }
        return res;
    }
};
// @lc code=end

