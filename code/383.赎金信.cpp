/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int hash[26] = {0};
        for(int i = 0;i < magazine.length();i++){
            hash[magazine[i] - 'a'] += 1;
        }
        for(int i = 0;i < ransomNote.length();i++){
            if(hash[ransomNote[i] - 'a'] <= 0) return false;
            hash[ransomNote[i] - 'a']--;
        }
        return true;
    }
};
// @lc code=end

