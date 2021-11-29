/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    //solution1:用hash和hash_tmp记录窗口，开销太大
    //solution2:用一个数组代替 +pre-pos指针--much faster！
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int cnt[26] = {0};
        for (const char& c:p) ++cnt[c-'a'];
        int pre = 0,pos = 0, len = p.size();
        while (pre + len <= s.size()&&pos < pre + len) {
            //cout<<pre<<" "<<pos<<endl;
            if (cnt[s[pos]-'a'] == 0) {
                ++pos;
                pre = pos;
            }
            else {
                while (pre + len <= s.size()&&pos < pre + len) {
                    if (cnt[s[pos]-'a']) --cnt[s[pos++]-'a'];
                    else {
                        while (pre < pos && s[pre] != s[pos]) ++cnt[s[pre++]-'a'];
                        if (pre == pos) break;
                        ++pre;
                        ++pos;
                    }
                }
                if (pos == pre + len) {
                    res.emplace_back(pre);
                    for (; pos < s.size(); ++pos) {
                        if (s[pos] == s[pre]) res.emplace_back(++pre);
                        else {
                            while (pre < pos && s[pre] != s[pos]) ++cnt[s[pre++]-'a'];
                            if(pre != pos) {
                                ++pos;
                                ++pre;
                            }
                            break;
                        }
                    }
                }
            }
        }
        return res;
        //"cbaebabacd"\n"abc"
        //"abab"\n"ab"
        //"abacbabc"\n"abc"
    }
};
// @lc code=end

