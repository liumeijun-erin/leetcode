/*
 * @lc app=leetcode.cn id=686 lang=cpp
 *
 * [686] 重复叠加字符串匹配
 */

// @lc code=start
class Solution {
public:
    //  思路：问题转换为在a*中找到b的第一个匹配字符串，RK算法，kmp算法
    // solution1-利用find，思路为把b往a+里面塞 O(m*n)
    // int repeatedStringMatch(string a, string b) {
    //     string tmp = "";
    //     int res = 0;
    //     while (tmp.find(b) == -1 && tmp.size() < b.size()+ 2 * a.size()) {
    //         tmp += a;
    //         ++res;
    //     }
    //     if(tmp.find(b) == -1) return -1;
    //     return res;
    //     //"abcabc"\n"bcabcabcabc" 2+6
    //     //"abc"\n"cabcabca"
    // }
    // solution2-字符串匹配Robin-Karp算法 O(m+n) :haystack needle
    // 将b往a*里面套,依次遍历a中各char作为起始点,当然是越靠前越好，只要求子集，不必要求a剩余部分
    // 明确strStr传导的为haystack中的长度%a.len
    // int strStr(string& haystack, string& needle) {
    //     int m = haystack.size(), n = needle.size();
    //     long long mod = 1e9 + 7;
    //     long long mul = 1337;
    //     long long hash_needle = 0;
    //     for (const char& c: needle) {
    //         hash_needle = (mul * hash_needle + c) % mod;
    //     }
    //     long long hash_haystack = 0;
    //     long long front_mul = 1;
    //     for (int i = 0; i < n-1; ++i) {
    //         hash_haystack = (hash_haystack * mul + haystack[i % m]) % mod;
    //         front_mul = (front_mul * mul) %mod;
    //     }
    //     for (int i = 0; i < m; ++i) {
    //         hash_haystack = (hash_haystack * mul + haystack[(i+n-1) % m]) % mod;
    //         cout<<hash_haystack<<" "<<hash_needle<<endl;
    //         if (hash_haystack == hash_needle) return i;
    //         hash_haystack = (hash_haystack - front_mul * haystack[i % m] ) % mod;
    //         // note:注意负数
    //         hash_haystack = (hash_haystack + mod)%mod;
    //     }
    //     return -1;
    // }
    //
    // solution3-字符串匹配KMP算法 p_id构建和搜索 O(m+n)
    int strStr(string& haystack, string& needle) {
        int m = haystack.size(), n = needle.size();
        vector<int> p_id(n);
        for (int i = 1,j = 0; i < n; ++i) {
            while (j > 0 && needle[i] != needle[j]) j = p_id[j-1];
            if (needle[i] == needle[j]) ++j;
            p_id[i] = j;
        }   
        for (int i = 0,j = 0; i - j < m;++i) {
            //note:边界条件
            while (j > 0 && haystack[i%m] != needle[j]) j = p_id[j-1];
            if (haystack[i%m] == needle[j]) ++j;
            if (j == n) return i-n+1;
            // note：注意返回第一个字母

        }
        return -1;
    }
    int repeatedStringMatch(string a, string b) {
        int res = strStr(a,b);
        if (res != -1) {
            res += b.size();
            if (res % a.length()) res = res/a.length() + 1;
            else res = res / a.length();
        }
        return res;
    }
};
// @lc code=end

