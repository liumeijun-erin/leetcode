/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */

// @lc code=start
class Solution {
public:
    string reverseVowels(string s) {
        int i = 0,j = s.size()-1;
        while(i < j){
            while(i < j&&s[i]!='e'&&s[i]!='a'&&s[i]!='i'&&s[i]!='o'&&s[i]!='u'&&s[i]!='A'&&s[i]!='E'&&s[i]!='I'&&s[i]!='O'&&s[i]!='U') ++i;
            while(i < j&&s[j]!='e'&&s[j]!='a'&&s[j]!='i'&&s[j]!='o'&&s[j]!='u'&&s[j]!='A'&&s[j]!='E'&&s[j]!='I'&&s[j]!='O'&&s[j]!='U') --j;
            swap(s[i],s[j]);
            ++i;
            --j;
        }
        return s;
    }
};
// @lc code=end

