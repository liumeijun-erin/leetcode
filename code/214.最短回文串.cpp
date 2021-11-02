/*
 * @lc app=leetcode.cn id=214 lang=cpp
 *
 * [214] 最短回文串
 */

// @lc code=start
class Solution {
public:
    //！！！判定回文数模板 ：kmp/base mod
    // 策略：转换--提取d前包含的最长回文串
    // 暴力超时+最大回文串模板没记住...
    //参考答案：！！！！KMP+变形/遍历len取模(都是字符串匹配算法变形，再kmp动态搜寻/将正、逆匹配起来)
    //solution1：base131 mod1000000007
    //取模方法思路：用特殊的数表示一个有序字符串，遍历截止位置比较该段字符串前后表示是否一致
    //left = ((long long)left * base + s[i]) % mod;
    //right = (right + (long long)mul * s[i]) % mod;
    //tip：一个方向遍历即可同时求出
    /*string shortestPalindrome(string s) {
        int n = s.size();
        int base = 131, mod = 1000000007;
        int left = 0, right = 0, mul = 1;
        int best = -1;
        for (int i = 0; i < n; ++i) {
            left = ((long long)left * base + s[i]) % mod;
            right = (right + (long long)mul * s[i]) % mod;
            if (left == right) {
                best = i;
            }
            mul = (long long)mul * base % mod;
        }
        string add = (best == n - 1 ? "" : s.substr(best + 1, n));
        reverse(add.begin(), add.end());
        return add + s;
    }*/
    //solution2：KMP算法变形(字符串匹配算法)
    //也是遍历len，对于每一对len的正逆进行匹配
    //这里与匹配串固定的情况不同之处在于每次更新一下next数组
    //kmp重点：next数组和calNext
    //！！！kmp变形：理解kmp过程，在过程中筛选！！！类似于leetcode321在构建树的过程中筛选
    //这里直接以reverse为haystack，原s为needle（因为想要得到的结果时原s的头部），遍历到
    //haystack尾部的时候needle位置即为解法
    //根本不用再遍历len：1-size挨个匹配
    void calNext(string& needle,vector<int>& next){
        int p = -1;
        for(int i = 1;i < needle.size();++i){//init:i = 1,p  =-1
            while(p != -1&&needle[p + 1] != needle[i]){
                p = next[p];
            }
            if(needle[p + 1] == needle[i]) ++p;
            next[i] = p;
        }
    }
    string shortestPalindrome(string s) {
        if(s.size() <= 1) return s;
        string haystack = s;
        reverse(haystack.begin(),haystack.end());
        vector<int> next(s.size(),-1);
        calNext(s,next);
        int p = -1;
        for(int i = 0;i < haystack.size();++i){//init:i = 0,p = -1
            while(p != -1&&haystack[i] != s[p + 1]){
                p = next[p];
            }
            if(haystack[i] == s[p+1]) ++p;
        }
        //cout<<p<<endl;
        string back_str = s.substr(p+1,s.size() - p - 1);
        reverse(back_str.begin(),back_str.end());  
        return back_str + s;
    }
    //failed-attempt：暴力
    /*bool isPalindrome(string& s,int& pos){
        int i = 0,j = pos;
        while(i < j){
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
    string shortestPalindrome(string s) {
        if(s.size() == 0) return s;
        int pos;
        for(pos = s.rfind(s[0]);pos > 0;){
            if(isPalindrome(s,pos)) break;
            else{
                pos = s.rfind(s[0],pos-1);
            }  
        }
        if(pos == -1) pos = 0;
        string tmp  = s.substr(pos+1,s.size() - pos-1);
        //cout<<tmp<<endl;
        reverse(tmp.begin(),tmp.end());
        return tmp + s;
        //"abbacd"
    }*/
};
// @lc code=end
