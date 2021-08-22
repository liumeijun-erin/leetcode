/*
 * @lc app=leetcode.cn id=696 lang=cpp
 *
 * [696] 计数二进制子串
 */

// @lc code=start
class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> count(2);
        int res = 0;
        //int cur = -1;超时,用cur标记当前访问超时
        for(int i = 0;i < s.size();++i){
            if(i>0&&s[i]!=s[i-1]) {
                res += min(count[0],count[1]);
                count[s[i]-'0']=0;
            }
            ++count[s[i]-'0'];
        }
        res += min(count[0],count[1]);
        return res;
    }
};
//"00100"
// @lc code=end

