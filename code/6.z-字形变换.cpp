/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> res(numRows,"");
        int i = 0;
        while(i < s.size()){
            for(int j = 0;j< numRows&&i < s.size();++i,++j){
                res[j] += s[i];
            }
            if(i == s.size()) break;
            for(int j = numRows-2;j > 0&&i < s.size();++i,--j){
                res[j] += s[i];
            }
            if(i == s.size()) break;
        }
        for(int i = 1 ;i < numRows;++i)  res[0] += res[i];
        return res[0];
    }
};
// @lc code=end

