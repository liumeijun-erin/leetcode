/*
 * @lc app=leetcode.cn id=5869 lang=cpp
 *
 * [5869] 两个回文子序列长度的最大乘积
 */

// @lc code=start
class Solution {
public:
    //本题不会写，参考了答案
    //策略：！！数据量不大的时候要敢于最简单暴力遍历！！！dfs!!!
    int maxProduct(string s) {
        string s1="",s2="";
        int res = 1;
        dfs(s,s1,s2,0,res);
        return res;
    }
    void dfs(string& s,string s1,string s2,int index,int&res){
        //tip1：这里这个顺序要设计好
        if(check(s1)&&check(s2)) {
            int ans = s1.size()*s2.size();
            res = max(ans,res);
        }
        //！！！先加再判断
        if(index == s.size()) return;
        //构造！而非筛选!
        dfs(s,s1+s[index],s2,index+1,res);
        dfs(s,s1,s2+s[index],index+1,res);
        dfs(s,s1,s2,index+1,res);
    }
    bool check(string& s){
        int l = 0,r = s.size()-1;
        while(l < r){
           if(s[l]!=s[r]) return false;
           ++l;
           --r;
        }
        return true;
        //边界"bb"
        //"accbcaxxcxx"
    }
};
// @lc code=end

