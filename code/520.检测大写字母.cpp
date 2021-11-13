/*
 * @lc app=leetcode.cn id=520 lang=cpp
 *
 * [520] 检测大写字母
 */

// @lc code=start
class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.length() == 1) return true;
        bool low;
        if (word[0] >= 'a') low = true;
        else {
            low = (word[1] >= 'a');
        }
        for(int i = 1; i < word.size(); ++i) {
            if(low && word[i] < 'a') return false;
            if(!low && word[i] >= 'a') return false;
        }
        return true;
    }
};
// @lc code=end

