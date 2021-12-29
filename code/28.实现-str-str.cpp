/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution {
public:
    /*int strStr(string haystack, string needle) {
        if(needle.length()==0){
            return 0;
        }
        int pos = haystack.find(needle);
        if(pos == string::npos){
            return -1;
        }
        else return pos;
    }*/
    //tip1:Rabin-Karp
    //hash code for str & substr
    //mod part can be quite tricky:curHash - (t * int(haystack[i - 1] - 'a')) % mod) + mod
    /*const long long  p = 10000019;
    const long long  mod = 1000000007;
    long long getHashCode(string s){
        long long hash = 0;
        for(int i = 0;i < s.length();i++){
            hash = (hash * p + s[i] - 'a') % mod;
        }
        return hash;
    }
    int strStr(string haystack, string needle){
        int len1 = haystack.length();
        int len2 = needle.length();
        if(len1 < len2) return -1;
        else if(len2 == 0) return 0;
        long long needleHash = getHashCode(needle);
        long long curHash = getHashCode(haystack.substr(0,len2));
        if(curHash == needleHash) return 0;
        long long t = 1;
        int i;
        for(i = 0; i < len2 - 1;i++){
            t = (t * p) % mod;
        }
        for(i = 1;i <= len1 - len2;i++){
            curHash = (((curHash - (t * int(haystack[i - 1] - 'a')) % mod) + mod) % mod * p ) % mod +  int(haystack[i + len2 - 1] - 'a');
            //cout<<curHash<<endl;
            //cout<<needleHash<<endl;
            if(curHash == needleHash) break;
        }
        if(i > len1 - len2) return -1;
        else return i;
    }*/
    //tip2:参考答案KMP算法，构造子串的最大前缀记录next数组
    //kmp算法：字符串匹配算法，可以在O(m+n)时间内匹配两个字符串
    int strStr(string haystack, string needle) {
        if (needle == "") return 0;
        else if(haystack.size() < needle.size()) return -1;
        vector<int> p_id(needle.size());
        for (int i = 1, j = 0;i < needle.size(); ++i) {
            while (j > 0 && needle[i] != needle[j]) j = p_id[j-1];
            if (needle[i] == needle[j]) ++j;
            p_id[i] = j;
        }
        for (int i = 0,j = 0;i < haystack.size(); ++i) {
            while (j > 0&&haystack[i] != needle[j]) j = p_id[j-1];
            if (haystack[i] == needle[j]) ++j;
            if (j == needle.size()) return i - needle.size() +1;
        }
        return -1;
    }
    //next[i] 表示 P[0] ~ P[i] 这一个子串，使得前k个字符恰等于后k个字符 的最大的k. 
    // void calNext(const string& needle,vector<int>& next) {
    //     for(int j = 1,p = -1;j < needle.length();++j){
    //         while(p > -1 && needle[p+1] != needle[j]){
    //             p = next[p];// 如果下一位不同，往前回溯
    //         }
    //         if(needle[p+1] == needle[j]) ++p;// 如果下一位相同，更新相同的最大前缀和最大后缀长
    //         next[j] = p;
    //     }
    // }
    // //abaabac
    // //0,-1,0,0,1,2,-1
    // int strStr(string haystack, string needle){
    //     int k = -1, n = haystack.length(), p = needle.length();
    //     if (p == 0) return 0;
    //     vector<int> next(p, -1); // -1表示不存在相同的最大前缀和后缀
    //     calNext(needle, next); // 计算next数组
    //     for (int i = 0; i < n; ++i) {
    //         while (k > -1 && needle[k+1] != haystack[i]) {
    //             k = next[k]; // 有部分匹配，往前回溯
    //         }
    //         if (needle[k+1] == haystack[i]) {
    //             ++k;
    //         }
    //         if (k == p-1) {
    //             return i - p + 1; // 说明k移动到needle的最末端，返回相应的位置
    //         }
    //     }
    //     return -1;
    // }
};
// @lc code=end

