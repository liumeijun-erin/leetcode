/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        // solution0: 直观思路要有：依次遍历各个位置，向左右延伸 O(n^n)
        // solution1: 在s0基础上，按len长度遍历并保存记录，省去中间部分遍历时间。O(nlogn)
        // int n = s.size();
        // vector<vector<bool> > dp(n, vector<bool> (n, false));
        // int len = 1,pos = 0;
        // for (int i = 1;i <= s.size(); ++i) {
        //     for (int j = 0; j + i - 1< s.size(); ++j) {
        //         if (s[j] == s[i + j - 1] && (i <= 2 ||dp[j+1][i+j-2])) {
        //             dp[j][j+i-1] = true;
        //             if (i > len) {
        //                 len = i;
        //                 pos = j;
        //             }
        //         }
        //     }
        // }
        // return s.substr(pos, len);
        // solution2：manacher's algorithm 
        // 参考：https://www.jianshu.com/p/392172762e55
        // 思路：还是在s0基础上，不按len划分还是从左到右遍历pos，然后左右遍历。利用回文中左右对称性值优化
        // pnt1：使用p[i]记录当前位置的回文半径
        // pnt2：记录当前到达的最右端mx以及对应的id。
        // 对于i < mx的情况，利用对称节约时间p[i] 从min(p[2*id - i], mx-i)开始遍历
        // pnt3：maxlength和index记录最终答案
        // pnt4：为了统一奇偶长度以及数组地位不越界改成$#1#2#3#4#形式。注意坐标转换
        // 时间复杂度O(n)
        // $#c#a#b#a#
        string tmp = "$";
        for (const char& ch: s) {
            tmp += "#";
            tmp += ch;
        }
        tmp += "#";
        int n = tmp.size();
        vector<int> radius(n, 0); // 明确radius含义两侧长度/半径
        int id = 0, mx = 0;
        int index = 0, max_len = -1;
        for (int i = 1; i < n-1; ++i) {
            if(i < mx) {
                if(radius[2*id - i] < mx - i) radius[i] = radius[2*id - i];
                else radius[i] = mx - i;
            }
            //cout<<radius[i]<<endl;
            while(i + radius[i]+1 < tmp.size() && i - radius[i]-1 >= 0 && tmp[i + radius[i]+1] == tmp[i-radius[i]-1]) ++radius[i];
            if (i + radius[i] > mx) {
                mx = i + radius[i];
                id = i;
            }
            if (radius[i] > max_len) { 
                max_len = radius[i];
                index = i;
            }
        }
        int start = (index - max_len) / 2; 
        return s.substr(start, max_len);
    }
};
// @lc code=end

