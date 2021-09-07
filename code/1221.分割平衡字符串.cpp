/*
 * @lc app=leetcode.cn id=1221 lang=cpp
 *
 * [1221] 分割平衡字符串
 */

// @lc code=start
class Solution {
public:
    int balancedStringSplit(string s) {
        int cnt = 0,res = 0;
        for(int i = 0;i < s.size();++i){
            if(s[i] == 'L') ++cnt;
            else --cnt;
            if(!cnt) ++res;
        }
        return res;
    }
};
// @lc code=end

