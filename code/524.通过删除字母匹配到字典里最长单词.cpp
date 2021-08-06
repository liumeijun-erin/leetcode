/*
 * @lc app=leetcode.cn id=524 lang=cpp
 *
 * [524] 通过删除字母匹配到字典里最长单词
 */

// @lc code=start
class Solution {
public:

    string findLongestWord(string s, vector<string>& dictionary) {
        //审题！！！删除某些元素也就是说要保证位序
        sort(dictionary.begin(),dictionary.end(),[](string a,string b){
            if(a.length() != b.length()) return a.length() > b.length();
            else return a < b;
        });
        for(const string& ss:dictionary){
            int i,j = 0;
            if(ss.size() > s.size()) continue;
            for(i= 0;i < ss.length();i++){
                while(j < s.length()&&s[j] != ss[i]) ++j;
                if(j >= s.length()) {
                    break;
                }
                ++j;
            }
            if(i == ss.length()) return ss;
        }
        return "";
    }
};
// @lc code=end

