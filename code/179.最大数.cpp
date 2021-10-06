/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start
class Solution {
    static bool cmp(string& s1,string& s2){
        if(s1 == s2) return s1 > s2;//注意边界
        if(s1.find(s2) == 0){
            string tmp  = s1;
            tmp.erase(0,s2.size());
            return cmp(tmp,s2);
        }
        else if(s2.find(s1) == 0){
            string tmp  = s2;
            tmp.erase(0,s1.size());
            return cmp(s1,tmp);//注意顺序重要
        }
        return s1 > s2;
    }
public:
    string largestNumber(vector<int>& nums) {
        vector<string> nums_s;
        bool allZero = true;
        for(const int&n:nums){
            //note:to_string
            if(n) allZero = false;
            nums_s.emplace_back(to_string(n));
        }
        if(allZero) return "0";
        sort(nums_s.begin(),nums_s.end(),cmp);
        string res = "";
        for(const string&s:nums_s){
            res +=  s; 
        }
        return res;
    }
    //[3,30,34,5,9],"9534330","9534303"
    //[111311, 1113],"1113111113","1113111311"
    //[432,43243],"43243243","43243432"
    
};
// @lc code=end

