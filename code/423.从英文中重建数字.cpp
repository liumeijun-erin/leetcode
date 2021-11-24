/*
 * @lc app=leetcode.cn id=423 lang=cpp
 *
 * [423] 从英文中重建数字
 */

// @lc code=start
class Solution {
public:
    //  容易超时所以预先分析
    //能固定z:0,w:2,u:4,x:6,g:8,h-8:3,s-6:7,o-0-2-4:1,v-7:5,i-5-6-8:9
    string originalDigits(string s) {
        // vector<string> words = {"zero","one","two","three","four",
        //                         \"five","six","seven","eight","nine"};
        vector<int> letter(26);
        for (const char& c: s) ++letter[c-'a'];
        vector<int> cnt(10);
        cnt[0] = letter['z'-'a'];
        cnt[2] = letter['w'-'a'];
        cnt[4] = letter['u'-'a'];
        cnt[6] = letter['x'-'a'];
        cnt[8] = letter['g'-'a'];
        cnt[1] = letter['o'-'a'] - cnt[0] - cnt[2] - cnt[4];
        cnt[3] = letter['h'-'a'] - cnt[8];
        cnt[7] = letter['s'-'a'] - cnt[6];
        cnt[5] = letter['v'-'a'] - cnt[7];
        cnt[9] = letter['i'-'a'] - cnt[5] - cnt[6] - cnt[8];
        string res = "";;
        for (int i = 0;i < 10;++i) {
            while(cnt[i]--) res += '0' + i;
        }
        return res;
    }
};
// @lc code=end

