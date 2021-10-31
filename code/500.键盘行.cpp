/*
 * @lc app=leetcode.cn id=500 lang=cpp
 *
 * [500] 键盘行
 */

// @lc code=start
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char,int> hash;
        vector<string> keyboard = vector<string> { "qwertyuiop", "asdfghjkl", "zxcvbnm"};
        int line_index = 1;
        for(const string& line:keyboard){
            for(const char& c:line) hash[c] = line_index;
            ++line_index;
        }
        vector<string> res;
        for(const string& s:words){
            line_index = -1;
            bool qualified = true;
            for(const char& c:s) {
                char tmp_c = c;
                if(c >= 'A' && c <= 'Z') tmp_c += 'a' - 'A';
                if(hash.count(tmp_c)==0||line_index != -1&&line_index != hash[tmp_c]) {
                    qualified = false;
                    break;
                }
                line_index = hash[tmp_c];
            }
            if(qualified) res.emplace_back(s);
        }
        return res;
    }
};
// @lc code=end

