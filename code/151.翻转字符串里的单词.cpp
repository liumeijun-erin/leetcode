/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 */

// @lc code=start
class Solution {
public:
    // note:参考答案，不用两边分别识别word加入left_s, right_s
    // 从头开始往后面塞即可
    // note2:可以对新string进行操作 而不用s.erase
    string reverseWords(string s) {
        string res = "";
        int pos = s.size()-1;
        while (pos >= 0) {
            while (pos >= 0 && s[pos] == ' ') --pos;
            if (pos < 0) break;
            int pre = pos;
            while(pre >= 0 && s[pre] != ' ') --pre;
            res += (s.substr(pre+1, pos-pre) + ' ');
            pos = pre;
        }
        if (res.size()) res.pop_back();
        return res;
    }
    //"  hello world  "
};
// @lc code=end

