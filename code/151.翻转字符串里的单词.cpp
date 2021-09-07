/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        int cnt = 0,size = s.size(),i = 0;
        while(i < s.size()&&s[i]==' '){
            ++i;
            ++cnt;
        }
        s.erase(0,i);
        while(cnt < size){
            i = 0;
            while(i < s.size()&&s[i]!=' '){
                ++i;
                ++cnt;
            }
            string tmp = s.substr(0,i);
            tmp = " " +tmp;
            while(cnt<size&&i < s.size()&&s[i]==' ') {
                ++i;
                ++cnt;
            }
            s.erase(0,i);
            s.insert(size-cnt,tmp);
        }
        while(s[0] == ' ') s.erase(0,1);
        return s;
    }
    //"  hello world  "
};
// @lc code=end

