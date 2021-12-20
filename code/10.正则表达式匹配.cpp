/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution {
public:
    // key pnt：对于0-1(*)处理可以不遍历所有可能截断i,而是在j侧中用||
    // bool isMatch(const char* s, const char* p) {
    //     if(*p == 0) return *s == 0;
    //     auto first_match = *s && (*s == *p || *p == '.');
    //     if (*(p+1) == '*') {
    //         return isMatch(s,p+2) || (first_match && isMatch(++s,p));
    //     }
    //     else {
    //         return (first_match && isMatch(++s,++p));
    //     }
    // }

    bool isMatch(string s, string p) {
        // solution1: dfp 
        // bool help(string& s, string& p, int i, int j) {
        //     cout<<i<<" "<<j<<endl;
        //     if (i == s.size() && j == p.size()) return true;
        //     if (j + 1 < p.size() && p[j + 1] == '*') {
        //         if (help(s, p, i, j+2)) return true;
        //         char c = p[j];
        //         for (; i < s.size(); ++i) {
        //             if (c == '.' ||s[i] == c) {
        //                 if (help(s, p, i+1, j+2)) return true;
        //             }
        //             else break;
        //         }
        //     }
        //     else {
        //         if (i < s.size() && j < p.size() && p[j] == '.' || s[i] == p[j]) return help(s, p, i+1, j+1);
        //     }
        //     return false;
        // }
        // bool isMatch(string s, string p) {
        //     return help(s,p,0,0);
        // }
        
        // solution2: 二维dp
        // 实质相同，只是dp二维数组记录开销更小
        // key pnt：对于0-1(*)处理可以不遍历所有可能截断i,而是在j侧中对下一步用||
        int m = s.size(), n = p.size();
        vector<vector<bool> > dp(m+1, vector<bool> (n+1, false));
        // 1.边界条件
        dp[0][0] = true;
        for (int i = 1; i <= n; ++i) {
            if(p[i-1] == '*') dp[0][i] = dp[0][i-2];
        }
        // 2.遍历边界
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j-1] == '.') dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '*') {
                    //3.tricky part: 对于这种0-无数多的选择.可以不用遍历所有i，而是用||在j这边做判断
                    if(p[j-2] == '.' || p[j-2] == s[i-1]) dp[i][j] = dp[i-1][j] || dp[i][j-2];  
                    // X* 用尽/ 还有
                    else dp[i][j] = dp[i][j-2];  // 没有用，还有
                }
                else dp[i][j] = (s[i-1] == p[j-1]) && dp[i-1][j-1];
            }
        }
        return dp[m][n];

        // solution3：递归,参考答案--可以是为对方法1从存储和遍历方法上的双重改进
        // 结合solution2中j侧两种判断||思想
        // tip：使用c_str数组，然后传导指针
        // return isMatch(s.c_str(), p.c_str());
    }
    
};
//"aa"\n"a*"
//"aab"\n"c*a*b"
//"a"\n".*..a*"
// @lc code=end

