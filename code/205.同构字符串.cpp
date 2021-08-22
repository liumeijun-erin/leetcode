/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //solution1:利用了stl勿忘一对一的限制
        /*unordered_map<char,char> m;
        unordered_set<char> ss;
        for(int i = 0;i < s.size();++i){
            if(m.count(s[i])){
                if(m[s[i]] != t[i]) return false;
            }
            else{
                if(ss.count(t[i])) return false;
                m[s[i]] = t[i];
                ss.insert(t[i]);
            }
        }
        return true;*/
        //solution2:
        vector<int> s_first_index(256,-1),t_first_index(256,-1);
        for(int i = 0;i < s.size();++i){
            if(s_first_index[s[i] - '\0']==-1&&t_first_index[t[i] - '\0']==-1){
                s_first_index[s[i] - '\0'] = i;
                t_first_index[t[i] - '\0'] = i;
            }
            else if(s_first_index[s[i] - '\0'] != t_first_index[t[i] - '\0']){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

