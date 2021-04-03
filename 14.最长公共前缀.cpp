/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0){
            return "";
        }
        int i;
        for(i = 0;i < strs[0].size();i++){
            int j = 1;
            while(j < strs.size()){
                if(i >= strs[j].size() || strs[j][i] != strs[j - 1][i]){
                    break;
                }
                j++;
            }
            if(j != strs.size()){
                break;
            }
        }
        return strs[0].substr(0,i);
    }
};
// @lc code=end

