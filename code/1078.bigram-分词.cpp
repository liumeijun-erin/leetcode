/*
 * @lc app=leetcode.cn id=1078 lang=cpp
 *
 * [1078] Bigram 分词
 */

// @lc code=start
// note:注意robin-karp可能有问题 可能是空格，可能是排列组合的奇异
// "jkypmsxd jkypmsxd kcyxdfnoa jkypmsxd kcyxdfnoa jkypmsxd kcyxdfnoa kcyxdfnoa jkypmsxd kcyxdfnoa"\n"kcyxdfnoa"\n"jkypmsxd"
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        int state = 0;
        vector<string> res;
        int pos = 0,next;
        while (pos < text.size()) {
            next = text.find(' ', pos);
            if (next == -1) break;
            string word = text.substr(pos, next-pos);
            if(state == 1) {
                if (word == second) {
                    int tmp = text.find(' ', next + 1);
                    if (tmp == -1) tmp = text.size();
                    res.emplace_back(text.substr(next+1, tmp-next-1));
                }
            }
            if(word != first) state = 0;
            else state = 1;
            pos = next+1;
        }
        return res;
    }
    // "we we will we will we will will we will"\n"will"\n"we"
    // "jkypmsxd jkypmsxd kcyxdfnoa jkypmsxd kcyxdfnoa jkypmsxd kcyxdfnoa kcyxdfnoa jkypmsxd kcyxdfnoa"\n"kcyxdfnoa"\n"jkypmsxd"
};
// @lc code=end

