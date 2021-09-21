/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //可优化：cnt有点麻烦，可以转换为string作为key
        vector<vector<string> > res;
        vector<vector<int> > cnt;
        for(const string& str:strs){
            vector<int> tmp(26,0);
            for(const char&ch:str){
                ++tmp[ch-'a'];
            }
            bool same = false;
            for(int i = 0;i < res.size();++i){
                if(res[i][0].size()!=str.size()) continue;
                same = true;
                for(int j = 0;j < 26;++j){
                    if(tmp[j]!=cnt[i][j]) {
                        same = false;
                        break;
                    }
                }
                if(same) {
                    res[i].emplace_back(str);
                    break;
                }
            }
            if(!same){
                cnt.emplace_back(tmp);
                res.emplace_back(vector<string> {str});
            }
        }
        return res;
    }
};
// @lc code=end

