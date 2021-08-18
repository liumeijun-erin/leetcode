/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //solution1:超时,q相当于bfs
        //"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"
        /*unordered_map<char,vector<string> > words;
        for(const string& word:wordDict){
            words[word[0]].emplace_back(word);
        }
        queue<int> q;
        q.emplace(0);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(const string& word:words[s[cur]]){
                if(cur+word.size() <= s.size()&&s.substr(cur,word.size())==word){
                    if(cur+word.size() == s.size()) return true;
                    q.emplace(cur+word.size());
                }
            }
        }
        return false;*/
        //solution2:参考答案，使用动态规划.!!!要熟练dp和搜索自底向上和自顶向下写法转换，dp快一点
        vector<bool> dp(s.size()+1,false);
        dp[0]=  true;
        for(int i = 1;i <= s.size();i++){
            for(const string& ss:wordDict){
                if(i >= ss.size()&&s.substr(i-ss.size(),ss.size())==ss){
                    dp[i] = dp[i-ss.size()]||dp[i];
                    //注意这里写法！！！一定是||因为有一个解即可
                }
            }
        }
        return dp[s.size()];
        //"cars"\n["car","ca","rs"]
    }
};
// @lc code=end

