/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 */

// @lc code=start
class Solution {
public:
    class Solution {
public:
    string reverseWords(string s) {
        int left = 0, right = s.size()-1;
        while (left < right) {
            while (left <= right && s[left] == ' ') ++left;
            while (left <= right && s[right] == ' ') --right;
            int left_tmp = left;
            while (left <= right && s[left] != ' ') ++left;
            if (left >= right) break;
            int right_tmp = right;
            while (left <= right && s[right] != ' ') --right;
            
            // left_tmp left-1 right+1 right_tmp
            string tmp_left = s.substr(left_tmp, left-left_tmp);
            string tmp_right = s.substr(right+1, right_tmp-right);
            // cout<<tmp_left<<" "<<tmp_right<<endl;
            int gap = left_tmp + tmp_right.size() - left;
            // cout<<gap<<endl;
            if (gap > 0) {
                for (int i = right + gap;i-gap >= left;--i) {
                    s[i] = s[i - gap];
                }
                left += gap;
                right += gap;
            }
            else if (gap < 0){
                for (int i = left-1+gap; i <= right-1+gap; ++i) {
                    s[i] = s[i-gap];
                }
                left += gap;
                right += gap;
            }
            for (const char& c: tmp_right) {
                s[left_tmp++] = c;
            }
            s[left_tmp++] = ' ';
            for (int i = tmp_left.size()-1; i>=0; --i) {
                s[right_tmp--] = tmp_left[i];
            }
            s[right_tmp--] = ' ';
            // cout<<s<<endl;
        }
        left = 0;
        // cout<<s<<endl;
        for (int pos = 0; pos < s.size(); ++pos) {
            if (s[pos] ==' ') {
                if (left != 0 && s[left-1] != ' ') s[left++] = ' ';
            }
            else s[left++] = s[pos];
        }
        if (s[left-1] == ' ') --left;
        return s.substr(0, left);
    }
};
};
// @lc code=end

