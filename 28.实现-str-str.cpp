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
    const long long  p = 10000019;
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
    }
    //tip2:kmp
};
// @lc code=end

